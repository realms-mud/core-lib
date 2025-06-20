//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("galley");
    addAlias("war galley");
    addAlias("oared ship");

    addAdjectives(({ "long", "narrow", "oared", "war", "single-masted" }));
    addDescriptionTemplate("a ##Adjective## galley with rows of oars and a single mast");

    addTimeOfDayDescription("dawn", ({
        ". The galley is shrouded in mist, oars shipped and sail furled",
        ". At dawn, rowers gather on the benches, ready for the day's journey",
        ". The long, narrow hull glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The galley is launched into calm water, oars dipping in unison",
        ". Crewmen check the rigging and prepare the sail",
        ". The air is fresh, and the galley is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The galley glides across the sunlit bay, oars flashing in the light",
        ". The air is warm, and the ship is used for patrol and transport",
        ". Sailors gather at the galley, preparing for the afternoon tide"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The galley is pulled ashore, oars stacked on the benches",
        ". Dockhands rest nearby, the galley lying ready",
        ". The ship is checked for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The galley is tied up, the day's work nearly done",
        ". The air cools, and the ship is packed away for the night",
        ". Lanterns cast long shadows over the galley as the dock empties"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The galley is bathed in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, the ship lying quiet",
        ". The scent of wet wood lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The galley is shrouded in darkness, only faintly lit by lanterns",
        ". Only the sound of water remains as the dock grows quiet",
        ". Lanterns cast dim light on the galley, its shape barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first launches",
        " as the galley is busy with the first patrols of spring",
        " with the air fresh and the ship glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the galley in constant use, drying quickly in the sun",
        " as the sun warms the dock, the ship is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the galley packed for the last big patrols before winter",
        " as the air turns crisp and the ship is checked for leaks",
        " with the dock quieter, but the ship still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the galley rimed with frost, wood stiff with cold",
        " as only the hardiest rowers brave the chill to use the ship",
        " with the ship stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a galley is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a galley sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a long galley, oars shipped, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made galley is tied to the dock, ready for use"
    );
    addItemTemplate(
        "The galley is a long, narrow warship with rows of oars and a single "
        "mast. It is tied to the dock, ready for patrol, transport, or battle. "
        "The wood is smooth and well-maintained, and the ship is marked with "
        "the insignia of the local fleet."
    );
}
