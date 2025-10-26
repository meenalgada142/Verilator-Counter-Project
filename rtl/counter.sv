module counter #(
    parameter WIDTH = 4  // Width of the counter (default: 4-bit)
)(
    input  logic clk,                     // Clock signal
    input  logic reset,                   // Synchronous reset
    input  logic en,                      // Enable signal
    output logic [WIDTH-1:0] count        // Counter output
);

    // Internal register to hold previous count value for assertions
    logic [WIDTH-1:0] count_q;

    // Track previous count value on every clock edge
    always_ff @(posedge clk) begin
        count_q <= count;
    end

    // Counter logic: increment when enabled, reset to zero when reset is high
    always_ff @(posedge clk) begin
        if (reset)
            count <= '0;                 // Reset counter to zero
        else if (en)
            count <= count + 1;          // Increment counter when enabled
    end

    // Assertions for functional correctness

    // Assert that counter increments correctly when enabled
    assert_increment: assert property (
        @(posedge clk) disable iff (reset)
        en |=> count == (count_q + 1) % (1 << WIDTH)
    ) else $error("[%0t] ASSERTION FAILED: en=1 but count=%0d, expected=%0d", $time, count, count_q);

    // Assert that counter holds its value when not enabled
    assert_hold: assert property (
        @(posedge clk) disable iff (reset)
        !en |=> count == count_q
    ) else $error("[%0t] ASSERTION FAILED: en=0 but count=%0d, expected=%0d", $time, count, count_q);

    // Assert that counter resets to zero when reset is asserted
    assert_reset_zero: assert property (
        @(posedge clk)
        reset |=> count == 0
    ) else $error("[%0t] ASSERTION FAILED: reset=1 but count=%0d, expected=0", $time, count);

endmodule
