//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("sailboat");
    addAlias("small sailboat");
    addAlias("boat");

    addAdjectives(({ "small", "nimble", "single-masted", "wooden", "white-sailed" }));
    addDescriptionTemplate("a ##Adjective## sailboat tied to the dock");

    addTimeOfDayDescription("dawn", ({
        ". The sailboat is slick with dew, its sail furled and ready",
        ". At dawn, the boat rocks gently at its mooring, awaiting the breeze",
        ". The hull glistens as the sun rises over the harbor"
        }));
    addTimeOfDayDescription("morning", ({
        ". The sailboat is launched into calm water, sail catching the wind",
        ". Dockworkers load baskets and gear into the sailboat",
        ". The air is fresh, and the boat is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The sailboat glides across the sunlit bay, sail billowing",
        ". The air is warm, and the boat is used for fishing and exploring",
        ". Sailors gather at the boat, preparing for the afternoon tide"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The sailboat is pulled ashore, sail drying in the sun",
        ". Dockhands rest nearby, the boat lying ready",
        ". The boat is checked for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The sailboat is tied up, the day's work nearly done",
        ". The air cools, and the boat is packed away for the night",
        ". Lanterns cast long shadows over the sailboat as the dock empties"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The sailboat is bathed in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, the boat lying quiet",
        ". The scent of wet wood lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The sailboat is shrouded in darkness, only faintly lit by lanterns",
        ". Only the sound of water remains as the dock grows quiet",
        ". Lanterns cast dim light on the boat, its shape barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh rigging for the season's first launches",
        " as the sailboat is busy with the first catches of spring",
        " with the air fresh and the boat glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the sailboat in constant use, drying quickly in the sun",
        " as the sun warms the dock, the boat is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the sailboat packed for the last big catches before winter",
        " as the air turns crisp and the boat is checked for leaks",
        " with the dock quieter, but the boat still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the sailboat rimed with frost, wood stiff with cold",
        " as only the hardiest workers brave the chill to use the boat",
        " with the boat stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a sailboat is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a sailboat sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy sailboat, sail furled, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made sailboat is tied to the dock, ready for use"
    );
    addItemTemplate(
        "The sailboat is a small, nimble vessel with a single mast and crisp "
        "white sail. It is tied to the dock, ready for fishing, exploring, or "
        "traveling the bay. The wood is smooth and well-maintained, and the "
        "boat is marked with the insignia of the local harbor. "
    );
}
