#!/usr/bin/env perl

BEGIN { push @INC, (".", ".."); }

use strict;
use warnings;
# use diagnostics;
# use Carp;

use QTestingUtils qw(runcurl load_reg filesizeIxNr);

my $datapath = "/home/ssachdev/approxalgos/GPU_Work_Final2/dataScience/QGPU/unit_tests/datagen2/data";

sub get_filename {
    my ($q_type, $data_size, $mode) = @_;
    my $file = $datapath . "/" . $data_size . "_" . $mode . "_" . $q_type . ".bin";
    return $file;
}

for my $q_type ( "I1", "I4" ) {
    print "=========================\n";
    print "RUNNING: " . $q_type . "\n";
    for my $data_size ( "1e5", "1e6", "1e7", "1e8", "1e9" ) {
        print "-------------------------\n";
        print "DATA SIZE: " . $data_size . "\n";
        print "-------------------------\n";
        load_reg("a", $q_type, $data_size, get_filename($q_type, $data_size, "incr_mod100"));
        load_reg("b", "I1", $data_size, get_filename("I1", $data_size, "evenones"));
        runcurl("gq f1f2_to_s d_fld1=b d_fld2=a op=sum");
        runcurl("gq f_to_s d_fld1=a op=sum");
    }
}
