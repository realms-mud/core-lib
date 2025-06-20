//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("seashells");
    addAdjectives(({ "scattered", "colorful", "spiraled", "gleaming", "tiny" }));

    addDescriptionTemplate("##Adjective## seashells scattered along the shore");

    addTimeOfDayDescription("dawn", ({
        ". The seashells glisten with dew, colors soft in the morning light",
        ". At dawn, the shells are cool and damp to the touch",
        ". Gulls pick among the shells for hidden morsels"
        }));
    addTimeOfDayDescription("noon", ({
        ". The seashells gleam in the midday sun, colors vivid",
        ". The sand is warm, and the shells are dry and smooth",
        ". Children collect the brightest shells along the tide line"
        }));
    addTimeOfDayDescription("night", ({
        ". The seashells are barely visible in the darkness",
        ". The air is cool, and the shells are damp with dew",
        ". Lanterns cast dim light on the shells, colors muted"
        }));

    addSeasonDescription("spring", ({
        " with new shells washed up by spring tides",
        " as the shells are checked for tiny crabs and creatures",
        " with the air fresh and the shells gleaming"
        }));
    addSeasonDescription("summer", ({
        " with the shells drying quickly in the sun",
        " as the sun beats down, the shells are a common sight",
        " with the air thick with the scent of salt and sand"
        }));
    addSeasonDescription("autumn", ({
        " with the shells scattered by autumn storms",
        " as the air turns crisp and the shells are piled by the tide",
        " with the beach quieter, but the shells still remain"
        }));
    addSeasonDescription("winter", ({
        " with the shells rimed with frost, colors pale in the cold",
        " as only the hardiest beachcombers brave the chill to collect them",
        " with the shells covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "seashells are scattered on the sand, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "seashells glint in the faint light, colors muted"
    );
    addDimLightDescriptionTemplate(
        "a collection of seashells lies on the sand, ready for collection"
    );
    addSomeLightDescriptionTemplate(
        "colorful seashells are scattered along the shore"
    );
}
