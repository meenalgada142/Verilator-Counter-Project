`timescale 1ns/1ps
import uvm_pkg::*;
`include "uvm_macros.svh"

// 🧩 Interface to connect DUT and UVM testbench
interface counter_if;
  logic clk;
  logic reset;
  logic en;
  logic [3:0] count;
endinterface

// 🧠 DUT: 4-bit counter with reset and enable
module counter (
  input  logic clk,
  input  logic reset,
  input  logic en,
  output logic [3:0] count
);
  always_ff @(posedge clk) begin
    if (reset)
      count <= 0;
    else if (en)
      count <= count + 1;
  end
endmodule

// 📦 Transaction: holds stimulus and observed output
class counter_transaction extends uvm_sequence_item;
  rand bit reset;
  rand bit en;
  bit [3:0] count;

  `uvm_object_utils(counter_transaction)
  function new(string name = "counter_transaction");
    super.new(name);
  endfunction
endclass

// 🔁 Sequence: generates randomized stimulus
class counter_sequence extends uvm_sequence #(counter_transaction);
  `uvm_object_utils(counter_sequence)
  function new(string name = "counter_sequence");
    super.new(name);
  endfunction

  task body();
    repeat (30) begin
      counter_transaction tr = counter_transaction::type_id::create("tr");
      assert(tr.randomize());
      start_item(tr);
      finish_item(tr);
    end
  endtask
endclass

// 🚗 Driver: applies stimulus to DUT
class counter_driver extends uvm_driver #(counter_transaction);
  virtual counter_if vif;
  `uvm_component_utils(counter_driver)

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    if (!uvm_config_db#(virtual counter_if)::get(this, "", "vif", vif))
      `uvm_fatal("NOVIF", "Virtual interface not set")
  endfunction

  task run_phase(uvm_phase phase);
    forever begin
      counter_transaction tr;
      seq_item_port.get_next_item(tr);
      vif.reset <= tr.reset;
      vif.en    <= tr.en;
      seq_item_port.item_done();
      @(posedge vif.clk);
    end
  endtask
endclass

// 👀 Monitor: observes DUT outputs and samples coverage
class counter_monitor extends uvm_monitor;
  virtual counter_if vif;
  uvm_analysis_port #(counter_transaction) ap;

  // 📊 Coverage group: tracks count values
  covergroup cg @(posedge vif.clk);
    coverpoint vif.count {
      bins all_vals[] = {[0:15]};
    }
  endgroup

  `uvm_component_utils(counter_monitor)

  function new(string name, uvm_component parent);
    super.new(name, parent);
    ap = new("ap", this);
    cg = new();
  endfunction

  function void build_phase(uvm_phase phase);
    if (!uvm_config_db#(virtual counter_if)::get(this, "", "vif", vif))
      `uvm_fatal("NOVIF", "Virtual interface not set")
  endfunction

  task run_phase(uvm_phase phase);
    forever begin
      @(posedge vif.clk);
      counter_transaction tr = counter_transaction::type_id::create("tr");
      tr.reset = vif.reset;
      tr.en    = vif.en;
      tr.count = vif.count;
      cg.sample(); // ✅ sample coverage
      ap.write(tr);
    end
  endtask
endclass

// ✅ Scoreboard: compares DUT output with expected count
class counter_scoreboard extends uvm_component;
  uvm_analysis_imp #(counter_transaction, counter_scoreboard) imp;
  bit [3:0] expected_count;

  `uvm_component_utils(counter_scoreboard)

  function new(string name, uvm_component parent);
    super.new(name, parent);
    imp = new("imp", this);
    expected_count = 0;
  endfunction

  function void write(counter_transaction tr);
    if (tr.reset)
      expected_count = 0;
    else if (tr.en)
      expected_count = expected_count + 1;

    if (tr.count !== expected_count)
      `uvm_error("SCOREBOARD", $sformatf("❌ Expected %0d, Got %0d", expected_count, tr.count))
    else
      `uvm_info("SCOREBOARD", $sformatf("✅ Count = %0d", tr.count), UVM_LOW);
  endfunction
endclass

// 🧱 Environment: connects driver, monitor, scoreboard
class counter_env extends uvm_env;
  counter_driver     drv;
  counter_monitor    mon;
  counter_scoreboard sb;

  `uvm_component_utils(counter_env)

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    drv = counter_driver::type_id::create("drv", this);
    mon = counter_monitor::type_id::create("mon", this);
    sb  = counter_scoreboard::type_id::create("sb", this);
  endfunction

  function void connect_phase(uvm_phase phase);
    mon.ap.connect(sb.imp);
  endfunction
endclass

// 🧪 Test: runs the sequence and environment
class counter_test extends uvm_test;
  counter_env env;
  counter_sequence seq;

  `uvm_component_utils(counter_test)

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    env = counter_env::type_id::create("env", this);
    seq = counter_sequence::type_id::create("seq");
  endfunction

  task run_phase(uvm_phase phase);
    phase.raise_objection(this);
    seq.start(env.drv.seq_item_port);
    phase.drop_objection(this);
  endtask
endclass

// 🧪 Top-level Testbench: connects DUT and launches UVM
module counter_uvm_tb;
  import uvm_pkg::*;
  `include "uvm_macros.svh"

  logic clk;
  counter_if counter_if();

  counter dut (
    .clk(counter_if.clk),
    .reset(counter_if.reset),
    .en(counter_if.en),
    .count(counter_if.count)
  );

  initial begin
    clk = 0;
    forever #5 clk = ~clk;
  end

  assign counter_if.clk = clk;

  initial begin
    uvm_config_db#(virtual counter_if)::set(null, "*", "vif", counter_if);
    run_test("counter_test");
  end
endmodule
