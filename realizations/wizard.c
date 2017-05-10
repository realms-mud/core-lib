//*****************************************************************************
// Class: wizard
// File Name: wizard.c
//
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: TBD
//
//*****************************************************************************
virtual inherit "/lib/realizations/player.c";

private string wizardLevel;

/////////////////////////////////////////////////////////////////////////////
public nomask int isRealizationOfWizard()
{
    return interactive();
}

