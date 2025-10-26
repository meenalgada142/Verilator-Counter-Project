# Verilator-Counter-Project

This project demonstrates a cycle-accurate counter simulation using **SystemVerilog** and **Verilator**, built around a modular **UVM-style testbench architecture** in C++. It showcases industry-standard verification practices including assertions, waveform tracing, scoreboarding, and functional coverage.

---

## 🧪 UVM-style Testbench Architecture

Although implemented in C++, the testbench mirrors Universal Verification Methodology (UVM) principles:

| UVM Concept         | C++ Equivalent         | Description |
|---------------------|------------------------|-------------|
| `uvm_sequence_item` | `CounterTransaction`   | Encapsulates stimulus (reset, enable) |
| `uvm_driver`        | `CounterDriver`        | Drives inputs to the DUT |
| `uvm_monitor`       | `CounterMonitor`       | Observes DUT outputs |
| `uvm_scoreboard`    | `CounterScoreboard`    | Compares DUT output with expected values |
| `uvm_coverage`      | `CounterCoverage`      | Tracks functional coverage of counter values |
| `uvm_env`           | `main()` function      | Instantiates and connects components |
| `uvm_phase`         | Simulation loop        | Drives time-based stimulus and evaluation |

This structure enables modularity, reusability, and clear separation of verification concerns.

---

## 🔧 Features

- Parameterized counter module (`WIDTH`)
- SystemVerilog assertions for:
  - Increment behavior when enabled
  - Hold behavior when disabled
  - Reset behavior
- C++ testbench with:
  - Driver, Monitor, Scoreboard, Coverage
- Waveform tracing via `dump.vcd` for GTKWave analysis
- Coverage report for all counter values

---

## 📂 Directory Structure
```
Verilator-Counter-Project/
├── rtl/
  │└── counter.sv
├── sim/
  │└── tb_counter.cpp
├── Waveforms/
  │└── counter_waveform.png
├── dump.vcd
├── Makefile
└── README.md
```

## ▶️ Build & Run Instructions

Make sure Verilator is installed and accessible in your terminal.

```bash
make clean  # Cleans build artifacts
make        # Builds and runs the simulation
```

## 📈 Waveform Snapshot
The image below shows the counter incrementing when en=1, holding when en=0, and resetting when reset=1.

![Counter waveform](Waveforms/waveform.png)


## 🧪 Simulation Output

```
Cycle 0: PASS - Count = 0
Cycle 1: PASS - Count = 0
Cycle 2: PASS - Count = 0
Cycle 3: PASS - Count = 0
Cycle 4: PASS - Count = 0
Cycle 5: PASS - Count = 1
Cycle 6: PASS - Count = 0
Cycle 7: PASS - Count = 0
Cycle 8: PASS - Count = 0
Cycle 9: PASS - Count = 0
Cycle 10: PASS - Count = 0
Cycle 11: PASS - Count = 1
Cycle 12: PASS - Count = 1
Cycle 13: PASS - Count = 0
Cycle 14: PASS - Count = 1
Cycle 15: PASS - Count = 1
Cycle 16: PASS - Count = 0
Cycle 17: PASS - Count = 1
Cycle 18: PASS - Count = 2
Cycle 19: PASS - Count = 2
Cycle 20: PASS - Count = 3
Cycle 21: PASS - Count = 4
Cycle 22: PASS - Count = 4
Cycle 23: PASS - Count = 0
Cycle 24: PASS - Count = 0
Cycle 25: PASS - Count = 0
Cycle 26: PASS - Count = 1
Cycle 27: PASS - Count = 2
Cycle 28: PASS - Count = 3
Cycle 29: PASS - Count = 3

Functional Coverage Report:
Count 0: 15 hits
Count 1: 7 hits
Count 2: 3 hits
Count 3: 3 hits
Count 4: 2 hits
Count 5: 0 hits
Count 6: 0 hits
Count 7: 0 hits
Count 8: 0 hits
Count 9: 0 hits
Count 10: 0 hits
Count 11: 0 hits
Count 12: 0 hits
Count 13: 0 hits
Count 14: 0 hits
Count 15: 0 hits

```

👤 Author
**Meenal Gada**  
Transitioning from AC Power Application Engineering to ASIC Verification  
GitHub: [meenalgada142](https://github.com/meenalgada142)
