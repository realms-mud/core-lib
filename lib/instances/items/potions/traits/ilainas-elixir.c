//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/traits/baseTrait.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("type", "effect");
    addSpecification("name", "Ilaina's Elixir");
    addSpecification("description", "You have quaffed the 'Ilaina's "
        "Elixir' potion and are currently benefitting from its effects.");
    addSpecification("root", "healthy");
    addSpecification("opposing root", "infirm");
    addSpecification("opinion", 10);
    addSpecification("duration", 300);
    addSpecification("bonus spell points", 250);
    addSpecification("bonus spellcraft", 10);
    addSpecification("expire message", "The effects of the 'Ilaina's "
        "Elixir' potion subside.");
}
