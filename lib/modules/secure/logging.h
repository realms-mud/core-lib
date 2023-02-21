//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef loggingModule_h
#define loggingModule_h

private int Submitted = 0;
private int Scheduled = 1;
private int Active = 2;
private int Completed = 3;
private int Rejected = 4;

private object service = 
    load_object("/lib/modules/secure/dataServices/loggingDataService.c");

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *getNewlySubmittedIssues()
{
    return service->getNewlySubmittedIssues();
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *getIssuesByPlayerName(string playerName)
{
    return service->getIssuesByPlayerName(playerName);
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *getIssuesByWizard(string wizard)
{
    return service->getIssuesByWizard(wizard);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveIssue(mapping data)
{
    service->saveIssue(data);
}

#endif
