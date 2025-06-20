//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("canoe");
    addAlias("small canoe");
    addAlias("paddle boat");

    addAdjectives(({ "small", "lightweight", "paddle", "wooden", "narrow" }));
    addDescriptionTemplate("a ##Adjective## canoe tied to the dock");

    addTimeOfDayDescription("dawn", ({
        ". The canoe is slick with dew, paddles resting inside",
        ". At dawn, fishermen prepare the canoe for the day's work",
        ". The canoe rocks gently at its mooring, ready for launch"
        }));
    addTimeOfDayDescription("morning", ({
        ". The canoe is launched into the calm morning water",
        ". Dockworkers load baskets and gear into the canoe",
        ". The air is fresh, and the canoe is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The canoe bobs in the sun, wood drying quickly",
        ". The air is warm, and the canoe is used for exploring the bay",
        ". Sailors gather at the canoe, preparing for the afternoon tide"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The canoe is pulled ashore, baskets heavy with the day's catch",
        ". Dockhands rest nearby, the canoe lying ready",
        ". The canoe is checked for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The canoe is tied up, the day's work nearly done",
        ". The air cools, and the canoe is packed away for the night",
        ". Lanterns cast long shadows over the canoe as the dock empties"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The canoe is bathed in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, the canoe lying quiet",
        ". The scent of wet wood lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The canoe is shrouded in darkness, only faintly lit by lanterns",
        ". Only the sound of water remains as the dock grows quiet",
        ". Lanterns cast dim light on the canoe, its shape barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first launches",
        " as the canoe is busy with the first catches of spring",
        " with the air fresh and the canoe glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the canoe in constant use, drying quickly in the sun",
        " as the sun warms the dock, the canoe is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the canoe packed for the last big catches before winter",
        " as the air turns crisp and the canoe is checked for leaks",
        " with the dock quieter, but the canoe still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the canoe rimed with frost, wood stiff with cold",
        " as only the hardiest workers brave the chill to use the canoe",
        " with the canoe stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a canoe is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a canoe sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy canoe, paddles resting inside, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made canoe is tied to the dock, ready for use"
    );
    addItemTemplate(
        "The canoe is a small, lightweight vessel with paddles resting inside. "
        "It is tied to the dock, ready for fishing, exploring, or traveling "
        "quiet waters. The wood is smooth and well-maintained, and the canoe "
        "is marked with the insignia of the local harbor."
    );
}
