//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "celibate");
    addSpecification("description", "You have chosen to abstain from "
        "marital and sexual relationships.");
    addSpecification("root", "celibate");
    addSpecification("opposing root", "hedonist");
    addSpecification("opinion", 10);
    addSpecification("opposing opinion", -10);
}
