//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("barrel of water");
    addAlias("water barrel");
    addAlias("barrel");

    addAdjectives(({ "wooden", "sealed", "fresh", "iron-banded", "water-filled" }));
    addDescriptionTemplate("a ##Adjective## barrel filled with fresh water");

    addTimeOfDayDescription("dawn", ({
        ". The barrel is cool and beaded with dew in the early light",
        ". At dawn, dockhands check the water barrel for leaks",
        ". The barrel's iron bands glisten as the sun rises"
        }));
    addTimeOfDayDescription("morning", ({
        ". The barrel is opened for sailors to fill their flasks",
        ". Dockworkers stack barrels of water for the day's voyages",
        ". The air is fresh, and the barrel is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The barrel sits in the sun, water sloshing inside",
        ". The air is warm, and the barrel is a welcome sight for thirsty workers",
        ". Sailors gather to refill their canteens"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The barrel is half-empty, water drawn for the afternoon heat",
        ". Dockhands rest nearby, the barrel standing ready",
        ". The barrel is checked for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The barrel is sealed and stored, the day's work nearly done",
        ". The air cools, and the barrel is packed away for the night",
        ". Lanterns cast long shadows over the barrels of water"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The barrel is packed away in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, barrels lying quiet",
        ". The scent of fresh water lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The barrel of water is left on the dock, silent in the night air",
        ". Only the faint sound of water sloshing remains as the dock grows quiet",
        ". Lanterns cast dim light on the barrels, their shapes barely visible"
        }));

    addSeasonDescription("spring", ({
        " with fresh water drawn from the first melt of the season",
        " as the barrel is filled for the first voyages of spring",
        " with the air fresh and the barrel glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the barrel in constant use, water drawn all day",
        " as the sun warms the dock, the barrel is a welcome sight",
        " with the air thick with the scent of wood and cool water"
        }));
    addSeasonDescription("autumn", ({
        " with the barrel packed for the last big voyages before winter",
        " as the air turns crisp and the barrel is checked for leaks",
        " with the dock quieter, but the barrel still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the barrel rimed with frost, water cold and clear",
        " as only the hardiest workers brave the chill to fetch water",
        " with the barrel stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a barrel of water is barely visible, stacked on the dock"
    );
    addLowLightDescriptionTemplate(
        "a barrel of water sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy barrel of water, iron bands glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made barrel of water is stacked on the dock, ready for use"
    );
    addItemTemplate(
        "The barrel is made of sturdy oak, bound with iron bands and filled "
        "with fresh water. It is stacked with others on the dock, ready to "
        "supply ships and sailors. The wood is cool and damp, and the barrel "
        "is marked with the insignia of the local merchant."
    );
}
