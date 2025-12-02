//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environmentalElement.c";

/////////////////////////////////////////////////////////////////////////////
public string Type()
{
    return "interior";
}

/////////////////////////////////////////////////////////////////////////////
protected int displayEntryMessage()
{
    return 1;
}
