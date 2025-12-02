//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("The Dagger Smith");
    welcomeMessage("Welcome to the dagger smith's shop");
    shopType("weapons");
    shopSubType("daggers");
}
