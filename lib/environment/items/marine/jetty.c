//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("jetty");
    addAdjectives(({ "stone", "weathered", "broad", "mossy", "harbor" }));

    addDescriptionTemplate("a ##Adjective## jetty extending into the water");

    addTimeOfDayDescription("dawn", ({
        ". The jetty is slick with dew, stones glistening in the light",
        ". At dawn, fishermen walk the jetty, casting lines into the water",
        ". The jetty stretches into the misty harbor"
        }));
    addTimeOfDayDescription("noon", ({
        ". The jetty is warm from the sun, moss drying on the stones",
        ". The harbor bustles as boats tie up along the jetty",
        ". The jetty is a favorite spot for townsfolk to stroll"
        }));
    addTimeOfDayDescription("night", ({
        ". The jetty is barely visible in the darkness",
        ". The air is cool, and the stones are damp with dew",
        ". Lanterns cast dim light along the jetty, shadows flickering"
        }));

    addSeasonDescription("spring", ({
        " with the jetty freshly cleared of winter debris",
        " as moss grows thick between the stones",
        " with the air fresh and the jetty busy with fishermen"
        }));
    addSeasonDescription("summer", ({
        " with the jetty in constant use, stones warm in the sun",
        " as the sun beats down, the jetty is a common sight",
        " with the air thick with the scent of salt and seaweed"
        }));
    addSeasonDescription("autumn", ({
        " with the jetty checked for damage before winter",
        " as the air turns crisp and the stones are slick with rain",
        " with the harbor quieter, but the jetty still stands ready"
        }));
    addSeasonDescription("winter", ({
        " with the jetty rimed with frost, stones stiff with cold",
        " as only the hardiest fishermen brave the chill to walk it",
        " with the jetty covered, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "a jetty extends into the water, barely visible in the gloom"
    );
    addLowLightDescriptionTemplate(
        "a jetty glints in the faint light, stones slick with dew"
    );
    addDimLightDescriptionTemplate(
        "a broad jetty extends into the harbor, ready for use"
    );
    addSomeLightDescriptionTemplate(
        "a well-kept jetty stretches into the water, boats tied alongside"
    );
}
