#ifndef XIANALYZER__XI_OMTTREE_H
#define XIANALYZER__XI_OMTTREE_H

// system include files
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "DataFormats/RecoCandidate/interface/TrackAssociation.h"

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Candidate/interface/VertexCompositeCandidate.h"
#include "DataFormats/Candidate/interface/VertexCompositeCandidateFwd.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/GeometryVector/interface/GlobalPoint.h"

#include "RecoVertex/KinematicFit/interface/KinematicParticleVertexFitter.h"
#include "RecoVertex/KinematicFit/interface/KinematicConstrainedVertexFitter.h"
#include "RecoVertex/KinematicFit/interface/TwoTrackMassKinematicConstraint.h"

#include "RecoVertex/KinematicFitPrimitives/interface/KinematicParticleFactoryFromTransientTrack.h"
#include "RecoVertex/KinematicFitPrimitives/interface/MultiTrackKinematicConstraint.h"

#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"

#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"

#include "TrackingTools/Records/interface/TransientTrackRecord.h"

#include "MagneticField/Engine/interface/MagneticField.h"

#include "TrackingTools/IPTools/interface/IPTools.h"

#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"

#include <TString.h>
#include <TVector3.h>
#include <TMatrixD.h>

#include <Math/Functions.h>
#include <Math/SVector.h>
#include <Math/SMatrix.h>

//ROOT includes
#include "TTree.h"

using namespace std;
using namespace reco;
using std::vector;


class V0XiOmTTreeProducer : public edm::EDAnalyzer
{
public:
	explicit V0XiOmTTreeProducer(const edm::ParameterSet&);
	~V0XiOmTTreeProducer();

private:
	virtual void beginJob();
	virtual void analyze(const edm::Event&, const edm::EventSetup&);
	virtual void endJob();

  // ----------member data ---------------------------

struct ParticleData{
    //Xi
                //Skim Cuts
                float trkchi2cut_;
                float dauTransImpactSig_; //La_pion
                float dauLongImpactSig_; //La_pion
                float batDauTransImpactSig_; //Xi_pion
                float batDauLongImpactSig_; //Xi_pion
                float casVtxSignificance3D_; //Xi_dls
                float vtxSignificance3D_; //La_dls
                //Hong Cuts
                float cas3DIpSigValue_;
                float casPi3DIpSigValue_;
                float VTrkPi3DIpSigValue_;
                float VTrkP3DIpSigValue_;
                float casFlightSigValue_;
                float distanceSigValue_; //lambda
    //General candidate parameters
                float eta_;
                float rapidity_;
                float dxySig1_;
                float dxySig2_;
                float dzSig1_;
                float dzSig2_;
                float vtxChi2_;
                float cosTheta_;
                float decayLSig_;
                float misIDMassForward_; // for Kshort  m1 = pion m2 = proton
                float misIDMassBackward_; //only for kshort
                float misIDMassEE_;
                float mass_;
                float pt_;
                int nhit1_;
                int nhit2_;
                int n_; //number of candidates
    //Event Parameters
                int nTrkAcc_; //Number of tracks that pass track selection and eta pT cut
                int nEvt_; //Multiplicity
                double xVtx_;
                double yVtx_;
                double zVtx_;
                double xVtxError_;
                double yVtxError_;
                double zVtxError_;
        } XI, OM, KS, LA;

    edm::EDGetTokenT<reco::VertexCompositeCandidateCollection> _v0Collection;
    edm::EDGetTokenT<reco::VertexCollection> _vertexCollName;
    edm::EDGetTokenT<reco::TrackCollection> _trkSrc;
    edm::EDGetTokenT<CaloTowerCollection> _towerSrc;

	TTree* XiTree;
	TTree* OmTree;
    TTree* KsTree;
    TTree* LaTree;

    TH1D* nEv;

    std::string v0CollName_;
    std::string v0IDName_;
    double multLow_;
    double multHigh_;
    double rapMin_;
    double rapMax_;
    double ptCut1_;
    double ptCut2_;
    double misIDMassCut_;
    double misIDMassCutEE_;
    double cent_bin_low_;
    double cent_bin_high_;
    int nHitCut1_;
    int nHitCut2_;

    bool doRap_;
    bool useCentrality_;
    //std::string treeName_;
};

#endif
