/*
 * Copyright (c) 2016, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#include "precompiled.hpp"

#ifndef PRODUCT

#include "utilities/internalVMTests.hpp"
#include "utilities/macros.hpp"
#include "utilities/ostream.hpp"

#define run_unit_test(unit_test_function_call)                \
  void unit_test_function_call();                             \
  run_test(#unit_test_function_call, unit_test_function_call);

void InternalVMTests::run_test(const char* name, void (*test)()) {
  tty->print_cr("Running test: %s", name);
  test();
}

void InternalVMTests::run() {
  tty->print_cr("Running internal VM tests");
  run_unit_test(TestDependencyContext_test);
  run_unit_test(test_semaphore);
  run_unit_test(TestOS_test);
  run_unit_test(TestReservedSpace_test);
  run_unit_test(TestReserveMemorySpecial_test);
  run_unit_test(TestVirtualSpace_test);
  run_unit_test(TestMetaspaceAux_test);
  run_unit_test(TestMetachunk_test);
  run_unit_test(TestVirtualSpaceNode_test);
  run_unit_test(TestGlobalDefinitions_test);
  run_unit_test(GCTimer_test);
  run_unit_test(arrayOopDesc_test);
  run_unit_test(CollectedHeap_test);
  run_unit_test(QuickSort_test);
  run_unit_test(GuardedMemory_test);
  run_unit_test(AltHashing_test);
  run_unit_test(TestNewSize_test);
  run_unit_test(TestOldSize_test);
  run_unit_test(TestKlass_test);
  run_unit_test(TestBitMap_test);
  run_unit_test(TestAsUtf8);
  run_unit_test(TestResourcehash_test);
  run_unit_test(ObjectMonitor_test);
  run_unit_test(Test_linked_list);
  run_unit_test(TestChunkedList_test);
  run_unit_test(JSON_test);
  run_unit_test(Test_log_tag_combinations_limit);
  run_unit_test(Test_logtarget);
  run_unit_test(Test_logstream);
  run_unit_test(Test_loghandle);
  run_unit_test(Test_logtargethandle);
  run_unit_test(Test_log_gctracetime);
  run_unit_test(Test_configure_stdout);
  run_unit_test(Test_logconfiguration_subscribe);
  run_unit_test(Test_log_prefix);
  run_unit_test(Test_log_big);
  run_unit_test(Test_logtagset_duplicates);
  run_unit_test(Test_logtagset_descriptions);
  run_unit_test(Test_log_file_startup_rotation);
  run_unit_test(Test_log_file_startup_truncation);
  run_unit_test(Test_invalid_log_file);
  run_unit_test(Test_multiline_logging);
  run_unit_test(DirectivesParser_test);
  run_unit_test(Test_TempNewSymbol);
#if INCLUDE_VM_STRUCTS
  run_unit_test(VMStructs_test);
#endif
#if INCLUDE_ALL_GCS
  run_unit_test(TestOldFreeSpaceCalculation_test);
  run_unit_test(TestG1BiasedArray_test);
  run_unit_test(TestBufferingOopClosure_test);
  run_unit_test(TestCodeCacheRemSet_test);
  if (UseG1GC) {
    run_unit_test(FreeRegionList_test);
    run_unit_test(IHOP_test);
  }
  run_unit_test(test_memset_with_concurrent_readers);
  run_unit_test(TestPredictions_test);
  run_unit_test(WorkerDataArray_test);
  run_unit_test(ParallelCompact_test);
#endif
  tty->print_cr("All internal VM tests passed");
}

#endif