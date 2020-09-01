//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string Identifier;
private string Name;
private object Creator;
private mapping Members = ([]);
private int TotalWeight = 0;

private mapping information = ([
    "experience earned": ([]),
    "best kill": ([]),
    "following": ([]),
    "npcs": ({})
]);

private object service =
    load_object("/lib/modules/secure/dataServices/partyDataService.c");


/////////////////////////////////////////////////////////////////////////////
private nomask void removeParty()
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask void loadParty()
{

}

/////////////////////////////////////////////////////////////////////////////
private nomask void saveParty()
{

}
