//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("barrel of rum");
    addAlias("rum barrel");
    addAlias("barrel");

    addAdjectives(({ "oak", "sealed", "aged", "iron-banded", "rum-filled" }));
    addDescriptionTemplate("a ##Adjective## barrel filled with dark rum");

    addTimeOfDayDescription("dawn", ({
        ". The barrel of rum is cool and sealed tight in the early light",
        ". At dawn, dockhands check the rum barrel for leaks",
        ". The barrel's iron bands glisten as the sun rises"
        }));
    addTimeOfDayDescription("morning", ({
        ". The barrel is rolled to the ship, ready for the day's voyage",
        ". Dockworkers stack barrels of rum for the crew",
        ". The air is fresh, and the barrel is cool to the touch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The barrel sits in the sun, the scent of rum faint in the air",
        ". The air is warm, and the barrel is a prized cargo",
        ". Sailors eye the barrel, eager for a taste"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The barrel is half-empty, rum drawn for the afternoon ration",
        ". Dockhands rest nearby, the barrel standing ready",
        ". The barrel is checked for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The barrel is sealed and stored, the day's work nearly done",
        ". The air cools, and the barrel is packed away for the night",
        ". Lanterns cast long shadows over the barrels of rum"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The barrel is packed away in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, barrels lying quiet",
        ". The scent of rum lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The barrel of rum is left on the dock, silent in the night air",
        ". Only the faint scent of rum remains as the dock grows quiet",
        ". Lanterns cast dim light on the barrels, their shapes barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new barrels arriving for the season's first voyages",
        " as the barrel is filled for the first celebrations of spring",
        " with the air fresh and the barrel glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the barrel in constant use, rum drawn all day",
        " as the sun warms the dock, the barrel is a welcome sight",
        " with the air thick with the scent of wood and rum"
        }));
    addSeasonDescription("autumn", ({
        " with the barrel packed for the last big voyages before winter",
        " as the air turns crisp and the barrel is checked for leaks",
        " with the dock quieter, but the barrel still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the barrel rimed with frost, rum cold and strong",
        " as only the hardiest workers brave the chill to fetch rum",
        " with the barrel stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a barrel of rum is barely visible, stacked on the dock"
    );
    addLowLightDescriptionTemplate(
        "a barrel of rum sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy barrel of rum, iron bands glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made barrel of rum is stacked on the dock, ready for use"
    );
    addItemTemplate(
        "The barrel is made of sturdy oak, bound with iron bands and filled "
        "with dark rum. It is stacked with others on the dock, ready to supply "
        "ships and sailors. The wood is stained and fragrant, and the barrel "
        "is marked with the insignia of the local distiller."
    );
}
