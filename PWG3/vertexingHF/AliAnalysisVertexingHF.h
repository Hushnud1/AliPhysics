#ifndef AliAnalysisVertexingHF_H
#define AliAnalysisVertexingHF_H
/* Copyright(c) 1998-2007, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

//-------------------------------------------------------------------------
//                      Class AliAnalysisVertexingHF
//            Reconstruction of heavy-flavour decay candidates
//      
//  Origin: E.Bruna, G.E.Bruno, A.Dainese, F.Prino, R.Romita, X.M.Zhang
//  Contact: andrea.dainese@lnl.infn.it
//-------------------------------------------------------------------------

#include <TNamed.h>
#include "AliESDVertex.h"
#include "AliAODRecoDecayHF.h"
#include "AliAODRecoDecayHF2Prong.h"
#include "AliAODRecoDecayHF3Prong.h"
#include "AliAODRecoDecayHF4Prong.h"
#include "AliAODRecoCascadeHF.h"
#include "AliAnalysisFilter.h"

class AliESDtrack;
class AliVEvent;
class AliAODVertex;

//-----------------------------------------------------------------------------
class AliAnalysisVertexingHF : public TNamed {
 public:
  //
  AliAnalysisVertexingHF();
  AliAnalysisVertexingHF(const AliAnalysisVertexingHF& source);
  AliAnalysisVertexingHF& operator=(const AliAnalysisVertexingHF& source); 
  virtual ~AliAnalysisVertexingHF();

  void FindCandidates(AliVEvent *event,
		      TClonesArray *aodVerticesHFTClArr,
		      TClonesArray *aodD0toKpiTClArr,
		      TClonesArray *aodJPSItoEleTClArr,
		      TClonesArray *aodCharm3ProngTClArr,
		      TClonesArray *aodCharm4ProngTClArr,
		      TClonesArray *aodDstarTClArr,
		      TClonesArray *aodLikeSign2ProngTClArr,
		      TClonesArray *aodLikeSign3ProngTClArr);

  void PrintStatus() const;
  void SetSecVtxWithKF() { fSecVtxWithKF=kTRUE; }
  void SetD0toKpiOn() { fD0toKpi=kTRUE; }
  void SetD0toKpiOff() { fD0toKpi=kFALSE; }
  void SetJPSItoEleOn() { fJPSItoEle=kTRUE; }
  void SetJPSItoEleOff() { fJPSItoEle=kFALSE; }
  void Set3ProngOn() { f3Prong=kTRUE; }
  void Set3ProngOff() { f3Prong=kFALSE; }
  void Set4ProngOn() { f4Prong=kTRUE; }
  void Set4ProngOff() { f4Prong=kFALSE; }
  void SetDstarOn() { fDstar=kTRUE; }
  void SetDstarOff() { fDstar=kFALSE; }
  void SetLikeSignOn() { fLikeSign=kTRUE; }
  void SetLikeSignOff() { fLikeSign=kFALSE; }
  Bool_t GetD0toKpi() { return fD0toKpi; }
  Bool_t GetJPSItoEle() { return fJPSItoEle; }
  Bool_t Get3Prong() { return f3Prong; }
  Bool_t Get4Prong() { return f4Prong; }
  Bool_t GetDstar()  { return fDstar; }
  Bool_t GetLikeSign() { return fLikeSign; }
  void SetFindVertexForDstar(Bool_t vtx=kTRUE) { fFindVertexForDstar=vtx; }
  void SetRecoPrimVtxSkippingTrks() 
    { fRecoPrimVtxSkippingTrks=kTRUE; fRmTrksFromPrimVtx=kFALSE;}
  void SetRmTrksFromPrimVtx() 
    {fRmTrksFromPrimVtx=kTRUE; fRecoPrimVtxSkippingTrks=kFALSE; }
  void SetTrackFilter(AliAnalysisFilter* trackF) { fTrackFilter = trackF; }
  void SetTrackFilterSoftPi(AliAnalysisFilter* trackF) { fTrackFilterSoftPi = trackF; }
  AliAnalysisFilter* GetTrackFilter() const { return fTrackFilter; }
  AliAnalysisFilter* GetTrackFilterSoftPi() const { return fTrackFilterSoftPi; }
  void SetD0toKpiCuts(Double_t cut0=1000.,Double_t cut1=100000.,
		      Double_t cut2=1.1,Double_t cut3=0.,Double_t cut4=0.,
		      Double_t cut5=100000.,Double_t cut6=100000.,
		      Double_t cut7=100000000.,Double_t cut8=-1.1); 
  void SetD0toKpiCuts(const Double_t cuts[9]); 
  void SetD0fromDstarCuts(Double_t cut0=1000.,Double_t cut1=100000.,
			  Double_t cut2=1.1,Double_t cut3=0.,Double_t cut4=0.,
			  Double_t cut5=100000.,Double_t cut6=100000.,
			  Double_t cut7=100000000.,Double_t cut8=-1.1); 
  void SetD0fromDstarCuts(const Double_t cuts[9]); 
  void SetBtoJPSICuts(Double_t cut0=1000.,Double_t cut1=100000.,
		      Double_t cut2=1.1,Double_t cut3=0.,Double_t cut4=0.,
		      Double_t cut5=100000.,Double_t cut6=100000.,
		      Double_t cut7=100000000.,Double_t cut8=-1.1); 
  void SetBtoJPSICuts(const Double_t cuts[9]); 
  void SetDplusCuts(Double_t cut0=1000.,Double_t cut1=0.,
		    Double_t cut2=0.,Double_t cut3=0.,Double_t cut4=0.,
		    Double_t cut5=0.,Double_t cut6=10000000000.,
		    Double_t cut7=0.,Double_t cut8=0.,
		    Double_t cut9=-1.1,Double_t cut10=0.,
		    Double_t cut11=10000000000.); 
  void SetDplusCuts(const Double_t cuts[12]); 
  void SetDsCuts(Double_t cut0=1000.,Double_t cut1=0.,
		Double_t cut2=0.,Double_t cut3=0.,Double_t cut4=0.,
		Double_t cut5=0.,Double_t cut6=10000000000.,
		Double_t cut7=0.,Double_t cut8=0.,
		Double_t cut9=-1.1,Double_t cut10=0.,
		Double_t cut11=10000000000., Double_t cut12=1000.); 
  void SetDsCuts(const Double_t cuts[13]); 
  void SetLcCuts(Double_t cut0=1000.,Double_t cut1=0.,
		 Double_t cut2=0.,Double_t cut3=0.,Double_t cut4=0.,
		 Double_t cut5=0.,Double_t cut6=10000000000.,
		 Double_t cut7=0.,Double_t cut8=0.,
		 Double_t cut9=-1.1,Double_t cut10=0.,
		 Double_t cut11=10000000000.); 
  void SetLcCuts(const Double_t cuts[12]); 
  void SetDstarCuts(Double_t cut0=1000., Double_t cut1=1000.,
                      Double_t cut2=-1., Double_t cut3=1000.,
                      Double_t cut4=1.6); 
  void SetDstarCuts(const Double_t cuts[5]); 
  void SetD0to4ProngsCuts(Double_t cut0=1000.,Double_t cut1=100000.,
                      Double_t cut2=0.,Double_t cut3=0.,Double_t cut4=0.,
                      Double_t cut5=-1.1,Double_t cut6=0.,
                      Double_t cut7=0.,Double_t cut8=0.);
  void SetD0to4ProngsCuts(const Double_t cuts[9]);
  const Double_t *GetD0toKpiCuts() const {return fD0toKpiCuts;}
  const Double_t *GetD0fromDstarCuts() const {return fD0fromDstarCuts;}
  const Double_t *GetBtoJPSICuts() const {return fBtoJPSICuts;}
  const Double_t *GetDplusCuts() const {return fDplusCuts;}
  const Double_t *GetDsCuts() const {return fDsCuts;}
  const Double_t *GetLcCuts() const {return fLcCuts;}
  const Double_t *GetDstarCuts() const {return fDstarCuts;}
  const Double_t *GetD0to4ProngsCuts() const {return fD0to4ProngsCuts;}

  //
 private:
  //
  enum { kBitDispl = 0, kBitSoftPi = 1 };

  Bool_t fInputAOD; // input from AOD (kTRUE) or ESD (kFALSE) 

  Int_t fAODMapSize; // size of fAODMap 
  Int_t *fAODMap; //[fAODMapSize] map between index and ID for AOD tracks

  Double_t fBzkG; // z componenent of field in kG

  Bool_t fSecVtxWithKF; // if kTRUE use KF vertexer, else AliVertexerTracks

  Bool_t fRecoPrimVtxSkippingTrks; // flag for primary vertex reco on the fly
                                   // for each candidate, w/o its daughters
  Bool_t fRmTrksFromPrimVtx; // flag for fast removal of daughters from 
                             // the primary vertex

  AliESDVertex *fV1; // primary vertex

  // flag to enable candidates production
  Bool_t fD0toKpi;   // D0->Kpi 
  Bool_t fJPSItoEle; // Jpsi->ee
  Bool_t f3Prong;    // D+,Ds,Lc
  Bool_t f4Prong;    // D0->Kpipipi
  Bool_t fDstar;     // D*->D0pi
  Bool_t fLikeSign;  // Like-sign pairs

  // single-track cuts
  AliAnalysisFilter *fTrackFilter; //  Track Filter for displaced vertices
  AliAnalysisFilter *fTrackFilterSoftPi; //  Track Filter for D* soft pion
  // candidates cuts
  Double_t fD0toKpiCuts[9]; // cuts on D0->Kpi candidates
                  // (to be passed to AliAODRecoDecayHF2Prong::SelectD0())
                          // 0 = inv. mass half width [GeV]   
                          // 1 = dca [cm]
                          // 2 = cosThetaStar 
                          // 3 = pTK [GeV/c]
                          // 4 = pTPi [GeV/c]
                          // 5 = d0K [cm]   upper limit!
                          // 6 = d0Pi [cm]  upper limit!
                          // 7 = d0d0 [cm^2]
                          // 8 = cosThetaPoint
  Double_t fD0fromDstarCuts[9]; // cuts on D0->Kpi candidates from D*
                        // (to be passed to AliAODRecoCascadeHF::SelectDstar())
                          // 0 = inv. mass half width [GeV]   
                          // 1 = dca [cm]
                          // 2 = cosThetaStar 
                          // 3 = pTK [GeV/c]
                          // 4 = pTPi [GeV/c]
                          // 5 = d0K [cm]   upper limit!
                          // 6 = d0Pi [cm]  upper limit!
                          // 7 = d0d0 [cm^2]
                          // 8 = cosThetaPoint
  Double_t fBtoJPSICuts[9]; // cuts on JPSI candidates
                  // (to be passed to AliAODRecoDecayHF2Prong::SelectBtoJPSI())
                          // 0 = inv. mass half width [GeV]   
                          // 1 = dca [cm]
                          // 2 = cosThetaStar (negative electron)
                          // 3 = pTP [GeV/c]
                          // 4 = pTN [GeV/c]
                          // 5 = d0O [cm]   upper limit!
                          // 6 = d0N [cm]  upper limit!
                          // 7 = d0d0 [cm^2]
                          // 8 = cosThetaPoint
  Double_t fDplusCuts[12]; // cuts on Dplus candidates
                  // (to be passed to AliAODRecoDecayHF3Prong::SelectDplus())
                          // 0 = inv. mass half width [GeV]   
                          // 1 = pTK [GeV/c]
                          // 2 = pTPi [GeV/c]
                          // 3 = d0K [cm]   lower limit!
                          // 4 = d0Pi [cm]  lower limit!
                          // 5 = dist12 (cm)
                          // 6 = sigmavert (cm)
                          // 7 = dist prim-sec (cm)
                          // 8 = pM=Max{pT1,pT2,pT3} (GeV/c)
                          // 9 = cosThetaPoint
                          // 10 = Sum d0^2 (cm^2)
                          // 11 = dca cut (cm)
  Double_t fDsCuts[13]; // cuts on Ds candidates
                        // (to be passed to AliAODRecoDecayHF3Prong::SelectDs())
                        // 0 = inv. mass half width [GeV]   
                        // 1 = pTK [GeV/c]
                        // 2 = pTPi [GeV/c]
                        // 3 = d0K [cm]   lower limit!
                        // 4 = d0Pi [cm]  lower limit!
                        // 5 = dist12 (cm)
                        // 6 = sigmavert (cm)
                        // 7 = dist prim-sec (cm)
                        // 8 = pM=Max{pT1,pT2,pT3} (GeV/c)
                        // 9 = cosThetaPoint
                        // 10 = Sum d0^2 (cm^2)
                        // 11 = dca cut (cm)
                        // 12 = inv. mass cut arounf phi and K0* [GeV]
   Double_t fLcCuts[12]; // cuts on Lambdac candidates
                        // (to be passed to AliAODRecoDecayHF3Prong::SelectLc())
                        // 0 = inv. mass half width [GeV]   
                        // 1 = pTP [GeV/c]
                        // 2 = pTPi abd pTK [GeV/c]
                        // 3 = d0P [cm]   lower limit!
                        // 4 = d0Pi and d0K [cm]  lower limit!
                        // 5 = dist12 (cm)
                        // 6 = sigmavert (cm)
                        // 7 = dist prim-sec (cm)
                        // 8 = pM=Max{pT1,pT2,pT3} (GeV/c)
                        // 9 = cosThetaPoint
                        // 10 = Sum d0^2 (cm^2)
                        // 11 = dca cut (cm)
  Double_t fDstarCuts[5]; // cuts on D* candidates
                        // (to be passed to AliAODRecoCascadeHF::SelectDstar())
                        // 0 = inv. mass half width of D* [GeV]
                        // 1 = half width of (M_Kpipi-M_Kpi) [GeV]
                        // 2 = PtMin of pi_s [GeV/c]
                        // 3 = PtMax of pi_s [GeV/c]
                        // 4 = theta, angle between the track of pi_s and D0 decay plane [rad]

  Double_t fD0to4ProngsCuts[9]; // cuts on D0->K3pi candidates
                        // (to be passed to AliAODRecoDecayHF4Prong::SelectD0())
                        // 0 = inv. mass half width of D0 [GeV]
                        // 1 = DCA between opposite sign tracks 
                        // 2 = Distance between primary and two tracks vertex fDist12toPrim
                        // 3 = Distance between primary and three tracks vertex fDist3toPrim
                        // 4 = Distance between primary and two tracks vertex fDist4toPrim
                        // 5 = Cosinus of the pointing angle
                        // 6 = Transverse momentum of the D0 candidate
                        // 7 = Mass Pi+Pi- = mass of the rho0
                        // 8 = PID cut (one K in the quadruplet)

  Bool_t fFindVertexForDstar; // reconstruct a secondary vertex or assume it's from the primary vertex
  //
  void AddDaughterRefs(AliAODVertex *v,AliVEvent *event,
		       TObjArray *trkArray) const;
  AliAODRecoDecayHF2Prong* Make2Prong(TObjArray *twoTrackArray1,AliVEvent *event,
				      AliAODVertex *secVert,Double_t dcap1n1,
				      Bool_t &okD0,Bool_t &okJPSI,Bool_t &okD0fromDstar) const;
  AliAODRecoDecayHF3Prong* Make3Prong(TObjArray *threeTrackArray,AliVEvent *event,
				      AliAODVertex *secVert,
				      Double_t dispersion,
				      AliAODVertex *vertexp1n1,
				      AliAODVertex *vertexp2n1,
				      Double_t dcap1n1,Double_t dcap2n1,Double_t dcap1p2,
				      Bool_t &ok3Prong) const;
  AliAODRecoDecayHF4Prong* Make4Prong(TObjArray *fourTrackArray,AliVEvent *event,
                                      AliAODVertex *secVert,
                                      AliAODVertex *vertexp1n1,
                                      AliAODVertex *vertexp1n1p2,
                                      Double_t dcap1n1,Double_t dcap1n2,
                                      Double_t dcap2n1,Double_t dcap2n2,
                                      Bool_t &ok4Prong) const;
  AliAODRecoCascadeHF* MakeCascade(TObjArray *twoTrackArray,AliVEvent *event,
				   AliAODVertex *secVert,
				   AliAODRecoDecayHF2Prong *rd2Prong,
				   Double_t dca,
				   Bool_t &okDstar) const;

  AliAODVertex* PrimaryVertex(TObjArray *trkArray=0x0,AliVEvent *event=0x0) const;
  AliAODVertex* ReconstructSecondaryVertex(TObjArray *trkArray,Double_t &dispersion,Bool_t useTRefArray=kTRUE) const;
  Bool_t SelectInvMass(Int_t decay,Int_t nprongs,
		       Double_t *px,Double_t *py,Double_t *pz) const;
  void   SelectTracksAndCopyVertex(AliVEvent *event,
				   TObjArray &seleTrksArray,Int_t &nSeleTrks,
				   UChar_t *seleFlags);
  void   SetPrimaryVertex(AliESDVertex *v1) { fV1 = v1; }
  Bool_t SingleTrkCuts(AliESDtrack *trk,Bool_t &okDisplaced,Bool_t &okSoftPi) const;
  //
  ClassDef(AliAnalysisVertexingHF,11);  // Reconstruction of HF decay candidates
};


#endif








