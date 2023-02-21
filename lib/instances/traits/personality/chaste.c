//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "chaste");
    addSpecification("description", "You have chosen to abstain from "
        "sexual relationships.");
    addSpecification("root", "celibate");
    addSpecification("opposing root", "hedonist");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
}
