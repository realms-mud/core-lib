//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/henchman.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfCompanion()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    henchman::create();
    customCombatAssessment("companion");
}
