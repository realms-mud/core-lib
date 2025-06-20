//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("crate of fish");
    addAlias("fish crate");
    addAlias("crate");

    addAdjectives(({ "wooden", "slatted", "fish-filled", "damp", "market" }));
    addDescriptionTemplate("a ##Adjective## crate of fish packed with ice");

    addTimeOfDayDescription("dawn", ({
        ". The crate is freshly packed, cool mist rising from the silvery fish",
        ". At dawn, the crate is stacked with others, ready for the morning market",
        ". The scent of fresh fish is sharp in the chilly morning air"
        }));
    addTimeOfDayDescription("morning", ({
        ". The crate is opened by vendors, scales glinting in the sunlight",
        ". Fishmongers sort through the crate, preparing for the day's sales",
        ". Gulls gather nearby, hoping for scraps from the morning catch"
        }));
    addTimeOfDayDescription("noon", ({
        ". The crate sits in the sun, fish packed in layers of crushed ice",
        ". The air is filled with the mingled scents of salt and fresh fish",
        ". Buyers inspect the crate, selecting the best of the catch"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The crate is half-empty, the remaining fish glistening in the light",
        ". Vendors repack the crate, keeping the fish cool with fresh ice",
        ". The dock is quieter, but the crate still draws the occasional customer"
        }));
    addTimeOfDayDescription("evening", ({
        ". The crate is nearly empty, only a few fish left at day's end",
        ". The air cools, and the crate is packed away for the night",
        ". Gulls pick at scraps left behind as the market closes"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The crate is closed and stacked with others in the fading light",
        ". Vendors tally their sales, the crate nearly empty",
        ". The scent of fish lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The crate is covered and left in the cool night air",
        ". Only the faint scent of fish remains as the dock grows quiet",
        ". Lanterns cast dim light on the stacked crates"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with the first catches of the season packed in fresh green seaweed",
        " as the crate overflows with a variety of fish from the spring run",
        " with the air fresh and the fish glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the crate packed with mackerel and herring, kept cool with ice",
        " as the sun warms the dock, vendors hurry to sell the day's catch",
        " with the air thick with the scent of fish and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the crate filled with the last big catches before winter",
        " as the air turns crisp and the fish are packed tightly for storage",
        " with the dock quieter, but the crate still draws eager buyers"
        }));
    addSeasonDescription("winter", ({
        " with the crate rimed with frost, fish kept cold by the winter air",
        " as only the hardiest vendors brave the chill to sell their catch",
        " with the crate stacked high, awaiting transport to the market"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a crate is barely visible, with only a faint glint from fish scales"
    );
    addLowLightDescriptionTemplate(
        "a crate of fish sits on the dock, its contents hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a crate packed with silvery fish, scales glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy crate filled with fresh fish, packed in layers of crushed ice"
    );
    addItemTemplate(
        "The crate is made of rough wood, its slats damp with seawater. Inside, "
        "freshly caught fish are packed in layers of crushed ice, their scales "
        "glistening. The scent of salt and fish is strong, and the crate is "
        "stamped with the mark of the local fishmonger."
    );
}
