//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private object service = 
    load_object("/lib/modules/secure/dataServices/regionDataService.c");

/////////////////////////////////////////////////////////////////////////////
private nomask mapping loadRegionData(string enterFrom, string location,
    mapping grid)
{
    return service->loadRegion(enterFrom, location, grid);
}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveegionData()
{

}
