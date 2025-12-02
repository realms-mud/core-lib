//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("barrel");
    addAlias("cask");
    addAlias("wooden barrel");

    addAdjectives(({ "wooden", "sturdy", "iron-banded", "cylindrical", "sealed" }));
    addDescriptionTemplate("a ##Adjective## barrel ready for storage or transport");

    addTimeOfDayDescription("dawn", ({
        ". The barrel is cool and damp with morning dew",
        ". At dawn, dockhands roll barrels into place for the day's work",
        ". The barrel's iron bands glisten in the soft light"
        }));
    addTimeOfDayDescription("morning", ({
        ". The barrel is opened by vendors, contents checked for quality",
        ". Dockworkers stack barrels, preparing for shipment",
        ". The scent of wood and whatever the barrel holds fills the air"
        }));
    addTimeOfDayDescription("noon", ({
        ". The barrel sits in the sun, wood warming and drying quickly",
        ". The air is filled with the mingled scents of wood, salt, and cargo",
        ". Buyers inspect the barrel, checking for leaks or damage"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The barrel is rolled onto a waiting cart, ready for delivery",
        ". Dockhands rest in the shade, barrels stacked nearby",
        ". The barrel is inspected for damage after a busy day"
        }));
    addTimeOfDayDescription("evening", ({
        ". The barrel is sealed and stored, the day's work nearly done",
        ". The air cools, and the barrel is packed away for the night",
        ". Lanterns cast long shadows over the stacked barrels"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The barrel is packed away in the fading light, ready for tomorrow",
        ". Dockworkers finish their tasks, barrels lying quiet",
        ". The scent of wood lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The barrel is left on the dock, silent in the night air",
        ". Only the faint creak of wood is heard as barrels shift in the breeze",
        ". Lanterns cast dim light on the barrels, their shapes barely visible"
        }));

    addSeasonDescription("spring", ({
        " with new barrels arriving for the season's first shipments",
        " as the barrel is filled with fresh goods from the spring catch",
        " with the air fresh and the barrel glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the barrel in constant use, filled and emptied all day",
        " as the sun dries the wood quickly between loads",
        " with the air thick with the scent of wood and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the barrel packed with the last big shipments before winter",
        " as the air turns crisp and the barrel is checked for leaks",
        " with the dock quieter, but the barrel still sees steady use"
        }));
    addSeasonDescription("winter", ({
        " with the barrel rimed with frost, wood stiff with cold",
        " as only the hardiest workers brave the chill to move barrels",
        " with the barrel stored away, awaiting the return of warmer weather"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a barrel is barely visible, stacked on the dock"
    );
    addLowLightDescriptionTemplate(
        "a barrel sits on the dock, its shape hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a sturdy wooden barrel, iron bands glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a well-made barrel is stacked on the dock, ready for use"
    );
    addItemTemplate(
        "The barrel is made of sturdy oak, bound with iron bands. It is "
        "stacked with others on the dock, ready to be filled or shipped. The "
        "wood is worn smooth by years of use, and the barrel is marked with "
        "the insignia of the local merchant."
    );
}
