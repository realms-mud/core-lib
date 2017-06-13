//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/materialAttributes.c";

private string lastCatch = 0;

/////////////////////////////////////////////////////////////////////////////
public nomask object isRealizationOf(string type)
{
    object ret = 0;
    if(type == "wizard")
    {
        ret = this_object();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string wizardInformation()
{
    return "Generic Wizard Info\n";
}