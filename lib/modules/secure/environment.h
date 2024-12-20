//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef environmentModule_h
#define environmentModule_h

private int currentYear;
private int currentTime;
private int currentDayOfYear;

private object service = 
    load_object("/lib/modules/secure/dataServices/environmentDataService.c");

/////////////////////////////////////////////////////////////////////////////
private nomask void loadEnvironmentalData()
{
    mapping data = service->loadEnvironmentData();
    if (mappingp(data))
    {
        currentTime = data["time"];
        currentDayOfYear = data["day"];
        currentYear = data["year"];
    }
    else
    {
        currentTime = 660;
        currentDayOfYear = 92;
        currentYear = 2942;
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveEnvironmentalData()
{
    service->saveEnvironmentData(currentTime, currentDayOfYear, currentYear);
}

#endif
