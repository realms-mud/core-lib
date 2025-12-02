//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("skiff");
    addAlias("small skiff");
    addAlias("fishing skiff");

    addAdjectives(({ "small", "wooden", "fishing", "open", "rowed" }));
    addDescriptionTemplate("a ##Adjective## skiff tied to the dock");

    addTimeOfDayDescription("dawn", ({
        ". The skiff is slick with dew, nets piled in the stern",
        ". At dawn, fishermen prepare the skiff for the day's work",
        ". The skiff rocks gently at its mooring, ready for launch"
        }));
    addTimeOfDayDescription("morning", ({
        ". The skiff is launched into the calm morning water",
        ". Dockworkers load baskets and gear into the skiff",
        ". The air is fresh, and the skiff is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The skiff bobs in the sun, wood drying quickly",
        ". The air is warm, and the skiff is used for fishing and ferrying",
        ". Sailors gather at the skiff, preparing for the afternoon tide"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The skiff is pulled ashore, nets heavy with the day's catch",
        ". Dockhands rest nearby, the skiff lying ready",
        ". The skiff is checked for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The skiff is tied up, the day's work nearly done",
        ". The air cools, and the skiff is packed away for the night",
        ". Lanterns cast long shadows over the skiff as the dock empties"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The skiff is bathed in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, the skiff lying quiet",
        ". The scent of wet wood lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The skiff is shrouded in darkness, only faintly lit by lanterns",
        ". Only the sound of water remains as the dock grows quiet",
        ". Lanterns cast dim light on the skiff, its shape barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new paint and fresh caulking for the season's first launches",
        " as the skiff is busy with the first catches of spring",
        " with the air fresh and the skiff glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the skiff in constant use, drying quickly in the sun",
        " as the sun warms the dock, the skiff is a common sight",
        " with the air thick with the scent of wet wood and water"
        }));
    addSeasonDescription("autumn", ({
        " with the skiff packed for the last big catches before winter",
        " as the air turns crisp and the skiff is checked for leaks",
        " with the dock quieter, but the skiff still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the skiff rimed with frost, wood stiff with cold",
        " as only the hardiest workers brave the chill to use the skiff",
        " with the skiff stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a skiff is barely visible, tied to the dock"
    );
    addLowLightDescriptionTemplate(
        "a skiff sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy skiff, nets piled in the stern, glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made skiff is tied to the dock, ready for use"
    );
    addItemTemplate(
        "The skiff is a small, sturdy vessel with nets piled in the stern. It "
        "is tied to the dock, ready for fishing, ferrying, or exploring the "
        "harbor. The wood is worn smooth by years of use, and the skiff is "
        "marked with the insignia of the local harbor. "
    );
}
