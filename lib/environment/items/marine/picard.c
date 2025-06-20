//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("picard");
    addAlias("picard boat");
    addAlias("fishing boat");

    addAdjectives(({ "small", "sturdy", "fishing", "wooden", "open" }));
    addDescriptionTemplate("a ##Adjective## picard fishing boat tied to the dock");

    addTimeOfDayDescription("dawn", ({
        ". The picard is shrouded in mist, nets piled in the stern",
        ". At dawn, fishermen prepare the picard for the day's work",
        ". The boat rocks gently at its mooring, ready for launch"
        }));
    addTimeOfDayDescription("morning", ({
        ". The picard is launched into the calm morning water",
        ". Dockworkers load baskets and gear into the picard",
        ". The air is fresh, and the boat is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The picard bobs in the sun, wood drying quickly",
        ". The air is warm, and the boat is used for fishing and ferrying",
        ". Sailors gather at the boat, preparing for the afternoon tide"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The picard is pulled ashore, nets heavy with the day's catch",
        ". Dockhands rest nearby, the boat lying ready",
        ". The boat is checked for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The picard is tied up, the day's work nearly done",
        ". The air cools, and the boat is packed away for the night",
        ". Lanterns cast long shadows over the picard as the dock empties"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The picard is bathed in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, the boat lying quiet",
        ". The scent of wet wood lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The picard is shrouded in darkness, only faintly lit by lanterns",
        ". Only the sound of water remains as the dock grows quiet",
        ". Lanterns cast dim light on the boat, its shape barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first launches",
        " as the picard is busy with the first catches of spring",
        " with the air fresh and the boat glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the picard in constant use, drying quickly in the sun",
        " as the sun warms the dock, the boat is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the picard packed for the last big catches before winter",
        " as the air turns crisp and the boat is checked for leaks",
        " with the dock quieter, but the boat still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the picard rimed with frost, wood stiff with cold",
        " as only the hardiest workers brave the chill to use the boat",
        " with the boat stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a picard is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a picard sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy picard, nets piled in the stern, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made picard is tied to the dock, ready for use"
    );
    addItemTemplate(
        "The picard is a small, sturdy fishing boat with nets piled in the "
        "stern. It is tied to the dock, ready for fishing, ferrying, or "
        "exploring the harbor. The wood is worn smooth by years of use, and "
        "the boat is marked with the insignia of the local harbor."
    );
}
