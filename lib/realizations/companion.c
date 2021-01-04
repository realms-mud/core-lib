//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/henchman.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfCompanion()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        "henchman"::reset(arg);
        customCombatAssessment("companion");
    }
}
