//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "vulgar");
    addSpecification("description", "You have a way with words. A rather "
        "obscene one full of 'arsebiscuits', 'shite', and 'bollocks'.");
    addSpecification("root", "vulgar");
    addSpecification("opposing root", "eloquent");
    addSpecification("opinion", -5);
    addSpecification("opposing opinion", -10);
}
