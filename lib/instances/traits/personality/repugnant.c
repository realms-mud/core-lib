//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "personality");
    addSpecification("name", "mordant");
    addSpecification("description", "You are a wholly detestable and "
        "utterly distasteful creature.");
    addSpecification("root", "harsh");
    addSpecification("opinion", -15);
}
