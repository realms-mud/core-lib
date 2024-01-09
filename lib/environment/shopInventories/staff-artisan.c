//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("Staff Artisan");
    welcomeMessage("Welcome to the staff artisan's shop");
    shopType("weapons");
    shopSubType("staffs");
}
