//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("barrel of tar");
    addAlias("tar barrel");
    addAlias("barrel");

    addAdjectives(({ "wooden", "sealed", "sticky", "iron-banded", "tar-filled" }));
    addDescriptionTemplate("a ##Adjective## barrel filled with sticky tar");

    addTimeOfDayDescription("dawn", ({
        ". The barrel of tar is cool and sticky with morning dew",
        ". At dawn, dockhands check the barrel for leaks",
        ". The scent of tar is sharp in the chilly morning air"
        }));
    addTimeOfDayDescription("morning", ({
        ". The barrel is opened by shipwrights, tar ready for repairs",
        ". Dockworkers stack barrels of tar, preparing for the day's work",
        ". The air is thick with the scent of tar and wood"
        }));
    addTimeOfDayDescription("noon", ({
        ". The barrel sits in the sun, tar warming and softening",
        ". The air is filled with the mingled scents of tar, wood, and salt",
        ". Shipwrights dip brushes into the barrel, sealing hulls and decks"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The barrel is sealed after use, tar cooling in the shade",
        ". Dockhands rest nearby, the barrel of tar standing ready",
        ". The barrel is inspected for leaks after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The barrel is closed and stored, the day's work nearly done",
        ". The air cools, and the barrel is packed away for the night",
        ". Lanterns cast long shadows over the barrels of tar"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The barrel is packed away in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, barrels of tar lying quiet",
        ". The scent of tar lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The barrel of tar is left on the dock, silent in the night air",
        ". Only the faint scent of tar remains as the dock grows quiet",
        ". Lanterns cast dim light on the barrels, their shapes barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new barrels of tar arriving for the season's repairs",
        " as the barrel is opened for the first ship maintenance of the year",
        " with the air fresh and the scent of tar strong"
        }));
    addSeasonDescription("summer", ({
        " with the barrel in constant use, tar softening in the heat",
        " as the sun warms the dock, shipwrights hurry to seal hulls",
        " with the air thick with the scent of tar and wood"
        }));
    addSeasonDescription("autumn", ({
        " with the barrel packed away after the last repairs before winter",
        " as the air turns crisp and the barrel is checked for leaks",
        " with the dock quieter, but the barrel still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the barrel rimed with frost, tar stiff with cold",
        " as only the hardiest workers brave the chill to use tar",
        " with the barrel stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a barrel of tar is barely visible, stacked on the dock"
    );
    addLowLightDescriptionTemplate(
        "a barrel of tar sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy barrel of tar, iron bands glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made barrel of tar is stacked on the dock, ready for use"
    );
    addItemTemplate(
        "The barrel is made of sturdy oak, bound with iron bands and marked "
        "with a black pitch stain. It is filled with thick, sticky tar, used "
        "for sealing ships and waterproofing ropes. The scent of tar is strong, "
        "and the barrel is marked with the insignia of the local shipwright."
    );
}
