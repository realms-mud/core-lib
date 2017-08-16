//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    addSpecification("type", "racial");
    addSpecification("name", "Celebnosti");
    addSpecification("description", "");
    addSpecification("root", "human");
    addSpecification("opposing root", "orc");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
    "baseTrait"::init();
}

