//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("Axe Smith");
    welcomeMessage("Welcome to the axe smith's shop");
    shopType("weapons");
    shopSubType("axes");
}
