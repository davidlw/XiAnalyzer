import FWCore.ParameterSet.Config as cms

from XiAnalyzer.XiAnalyzer.hadroncorrelationgen_cfi import *

HadronCorrelationGen = HadronCorrelation.clone(
            doGen = cms.bool(True)
        )
