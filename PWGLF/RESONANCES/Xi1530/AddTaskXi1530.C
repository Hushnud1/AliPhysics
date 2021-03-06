AliAnalysisTaskXi1530* AddTaskXi1530(const char *taskname = "Xi1530"
                                     , const char *option = "LHC16k"
                                     , int nmix=20
                                     , const char* suffix = "")
{
    AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();
    if (!mgr) {
        return 0x0;
    }
    if (!mgr->GetInputEventHandler()) {
        return 0x0;
    }
    TString foption = option;
    AliAnalysisTaskXi1530 *taskXi1530 = new AliAnalysisTaskXi1530(Form("%s%s", taskname,suffix), Form("%s_%s", taskname, option));
    //taskXi1530 -> SetFilterBit(768);
    std::cout << "AliAnaylsisTaskXi1530:: Option: " << option << std::endl;
    if(foption.Contains("MC")){
        taskXi1530->SetIsMC(kTRUE); // default: kFALSE
        std::cout << "AliAnaylsisTaskXi1530:: MC mode " << std::endl;
        if (foption.Contains("Gen")){
            taskXi1530->SetIsPrimaryMC(kFALSE); // default: kTRUE
            std::cout << "<GENERAL PURPOSE MC>" << std::endl;
        }
    }
    if(foption.Contains("AA")){
        taskXi1530->SetIsAA(kTRUE); // default: kFALSE
        std::cout << "AliAnaylsisTaskXi1530:: AA mode " << std::endl;
    }
    if(foption.Contains("Mix")){
        taskXi1530->SetMixing(kTRUE); // default: kFALSE
        std::cout << "AliAnaylsisTaskXi1530:: Event Mix(" << nmix << ") mode " << std::endl;
    } 
    if(foption.Contains("HM")){
        taskXi1530->SetHighMult(kTRUE); // default: kFALSE
        std::cout << "AliAnaylsisTaskXi1530:: HighMultV0 mode " << std::endl;
    }  
    if(foption.Contains("SYS")){
        taskXi1530->SetSystematics(kTRUE); // default: kFALSE
        std::cout << "AliAnaylsisTaskXi1530:: Systematic Study mode " << std::endl;
    } 
    taskXi1530 -> SetnMix(nmix);
    
    if(!taskXi1530) return 0x0;
    mgr->AddTask(taskXi1530);
    
    
    AliAnalysisDataContainer *cinput = mgr->GetCommonInputContainer();
    AliAnalysisDataContainer *coutputXi1530 = mgr->CreateContainer(Form("%s%s", taskname, suffix), TList::Class(), AliAnalysisManager::kOutputContainer, "AnalysisResults.root");

    mgr->ConnectInput(taskXi1530, 0, cinput);
    mgr->ConnectOutput(taskXi1530, 1, coutputXi1530);

    return taskXi1530;
}

