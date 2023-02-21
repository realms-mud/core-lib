//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "epicurean");
    addSpecification("description", "You have refined, decriminating "
        "tastes and are prone to indulge in them.");
    addSpecification("root", "refined");
    addSpecification("opposing root", "crude");
    addSpecification("opinion", 5);
    addSpecification("opposing opinion", -5);
}
