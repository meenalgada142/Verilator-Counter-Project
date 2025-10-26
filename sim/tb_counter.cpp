#include "Vcounter.h"              // Verilated model header
#include "verilated.h"             // Core Verilator functionality
#include "verilated_vcd_c.h"       // VCD waveform tracing
#include <iostream>
#include <map>
#include <cstdlib>

const int COUNTER_WIDTH = 4;       // Width of the counter
const int SIM_CYCLES = 30;         // Total simulation cycles

// Structure for driving inputs to the DUT
struct CounterTransaction {
    bool reset;
    bool en;
};

// Driver class: applies stimulus to the DUT
class CounterDriver {
public:
    Vcounter* dut;
    CounterDriver(Vcounter* d) : dut(d) {}
    void drive(const CounterTransaction& tr) {
        dut->reset = tr.reset;
        dut->en = tr.en;
    }
};

// Monitor class: observes DUT outputs
class CounterMonitor {
public:
    Vcounter* dut;
    CounterMonitor(Vcounter* d) : dut(d) {}
    int observe() {
        return dut->count;
    }
};

// Scoreboard class: compares DUT output with expected value
class CounterScoreboard {
public:
    void check(int observed, int expected, int cycle) {
        if (observed != expected) {
            std::cout << "Cycle " << cycle << ": MISMATCH - Expected " << expected << ", Got " << observed << std::endl;
        } else {
            std::cout << "Cycle " << cycle << ": PASS - Count = " << observed << std::endl;
        }
    }
};

// Coverage class: tracks how many times each count value was seen
class CounterCoverage {
public:
    std::map<int, int> count_seen;
    void sample(int count) {
        count_seen[count]++;
    }
    void report() {
        std::cout << "\nFunctional Coverage Report:" << std::endl;
        for (int i = 0; i < (1 << COUNTER_WIDTH); i++) {
            std::cout << "Count " << i << ": " << count_seen[i] << " hits" << std::endl;
        }
    }
};

// Required by Verilator for time tracking
double sc_time_stamp() { return 0; }

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vcounter* dut = new Vcounter;

    // Enable waveform tracing
    VerilatedVcdC* tfp = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    dut->trace(tfp, 99);
    tfp->open("dump.vcd");

    // Instantiate testbench components
    CounterDriver driver(dut);
    CounterMonitor monitor(dut);
    CounterScoreboard scoreboard;
    CounterCoverage coverage;

    int expected_count = 0;

    // Main simulation loop
    for (int cycle = 0; cycle < SIM_CYCLES; cycle++) {
        CounterTransaction tr;
        tr.reset = (rand() % 10 < 2);  // ~20% chance of reset
        tr.en = (rand() % 2);          // 50% chance of enable

        // Manual overrides for deterministic behavior
        if (cycle == 14) tr.en = 1;
        if (cycle == 15) tr.en = 0;
        if (cycle == 16) tr.reset = 1;
        if (cycle == 17) { tr.reset = 0; tr.en = 1; }

        // Update expected count before rising edge
        if (tr.reset)
            expected_count = 0;
        else if (tr.en)
            expected_count = (expected_count + 1) & ((1 << COUNTER_WIDTH) - 1);

        // Falling edge: drive inputs
        dut->clk = 0;
        driver.drive(tr);
        dut->eval();
        tfp->dump(cycle * 2);

        // Rising edge: evaluate DUT
        dut->clk = 1;
        dut->eval();
        tfp->dump(cycle * 2 + 1);

        // Observe and check output
        int observed = monitor.observe();
        scoreboard.check(observed, expected_count, cycle);
        coverage.sample(observed);
    }

    // Final coverage report
    coverage.report();

    // Cleanup
    tfp->close();
    delete dut;
    return 0;
}
