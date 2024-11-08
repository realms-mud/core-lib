//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "deceptive");
    addSpecification("description", "What's the harm in a little "
        "stretching of the truth if it gets you a win? None. You're "
        "not one to brazenly lie, but you have no qualms with the "
        "subtleties of twisting the truth to suit your narrative.");
    addSpecification("root", "dishonorable");
    addSpecification("opposing root", "honorable");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
    addSpecification("penalty to diplomacy", 1);
    addSpecification("bonus bluff", 1);
}
