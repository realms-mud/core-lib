//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("boat ramp");
    addAlias("ramp");
    addAlias("launch ramp");

    addAdjectives(({ "wooden", "sloped", "sturdy", "dockside", "launch" }));
    addDescriptionTemplate("a ##Adjective## boat ramp sloping into the water");

    addTimeOfDayDescription("dawn", ({
        ". The ramp is slick with dew, wood glistening in the early light",
        ". At dawn, fishermen prepare to launch their boats",
        ". The ramp slopes gently into the water, ready for the day's work"
        }));
    addTimeOfDayDescription("morning", ({
        ". The ramp is busy with boats being launched and retrieved",
        ". Dockworkers guide vessels down the ramp into the water",
        ". The air is fresh, and the ramp is wet from splashing waves"
        }));
    addTimeOfDayDescription("noon", ({
        ". The ramp sits in the sun, wood drying quickly",
        ". The air is warm, and the ramp is used for hauling boats ashore",
        ". Sailors gather at the ramp, preparing for the afternoon tide"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The ramp is quieter, most boats already launched",
        ". Dockhands rest nearby, the ramp standing ready",
        ". The ramp is checked for damage after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The ramp is slick with evening mist, wood cool to the touch",
        ". The air cools, and the ramp is empty as boats return",
        ". Lanterns cast long shadows over the ramp as the dock empties"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The ramp is bathed in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, the ramp lying quiet",
        ". The scent of wet wood lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The ramp is shrouded in darkness, only faintly lit by lanterns",
        ". Only the sound of water remains as the dock grows quiet",
        ". Lanterns cast dim light on the ramp, its shape barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new boards and fresh paint marking the start of the season",
        " as the ramp is busy with the first launches of spring",
        " with the air fresh and the ramp glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the ramp in constant use, drying quickly in the sun",
        " as the sun warms the dock, the ramp is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the ramp packed for the last big launches before winter",
        " as the air turns crisp and the ramp is checked for wear",
        " with the dock quieter, but the ramp still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the ramp rimed with frost, boards stiff with cold",
        " as only the hardiest workers brave the chill to use the ramp",
        " with the ramp stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a boat ramp is barely visible, sloping into the water"
    );
    addLowLightDescriptionTemplate(
        "a boat ramp sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy boat ramp, boards glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made boat ramp slopes into the water, ready for use"
    );
    addItemTemplate(
        "The boat ramp is made of sturdy planks, sloping gently into the water. "
        "It is used for launching and retrieving small boats, and the boards "
        "are worn smooth by years of use. The ramp is marked with the insignia "
        "of the local harbor."
    );
}
