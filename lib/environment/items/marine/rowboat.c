//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("rowboat");
    addAlias("boat");
    addAlias("small boat");

    addAdjectives(({ "small", "wooden", "oared", "fishing", "open" }));
    addDescriptionTemplate("a ##Adjective## rowboat tied to the dock");

    addTimeOfDayDescription("dawn", ({
        ". The rowboat is slick with dew, oars resting across the thwarts",
        ". At dawn, fishermen prepare the rowboat for the day's work",
        ". The boat rocks gently at its mooring, ready for launch"
        }));
    addTimeOfDayDescription("morning", ({
        ". The rowboat is launched into the calm morning water",
        ". Dockworkers load nets and baskets into the rowboat",
        ". The air is fresh, and the boat is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The rowboat bobs in the sun, wood drying quickly",
        ". The air is warm, and the boat is used for ferrying goods",
        ". Sailors gather at the boat, preparing for the afternoon tide"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The rowboat is pulled ashore, nets heavy with the day's catch",
        ". Dockhands rest nearby, the boat lying ready",
        ". The boat is checked for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The rowboat is tied up, the day's work nearly done",
        ". The air cools, and the boat is packed away for the night",
        ". Lanterns cast long shadows over the rowboat as the dock empties"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The rowboat is bathed in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, the boat lying quiet",
        ". The scent of wet wood lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The rowboat is shrouded in darkness, only faintly lit by lanterns",
        ". Only the sound of water remains as the dock grows quiet",
        ". Lanterns cast dim light on the boat, its shape barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first launches",
        " as the rowboat is busy with the first catches of spring",
        " with the air fresh and the boat glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the rowboat in constant use, drying quickly in the sun",
        " as the sun warms the dock, the boat is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the rowboat packed for the last big catches before winter",
        " as the air turns crisp and the boat is checked for leaks",
        " with the dock quieter, but the boat still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the rowboat rimed with frost, wood stiff with cold",
        " as only the hardiest workers brave the chill to use the boat",
        " with the boat stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a rowboat is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a rowboat sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy rowboat, oars resting across the thwarts, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made rowboat is tied to the dock, ready for use"
    );
    addItemTemplate(
        "The rowboat is a small, sturdy vessel with oars resting across the "
        "thwarts. It is tied to the dock, ready for fishing, ferrying, or "
        "exploring the harbor. The wood is worn smooth by years of use, and "
        "the boat is marked with the insignia of the local harbor."
    );
}
