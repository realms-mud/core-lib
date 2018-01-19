//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

/////////////////////////////////////////////////////////////////////////////
public string Type()
{
    return "terrain";
}

/////////////////////////////////////////////////////////////////////////////
protected int displayWeatherDetails()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected int displayEntryMessage()
{
    return 1;
}