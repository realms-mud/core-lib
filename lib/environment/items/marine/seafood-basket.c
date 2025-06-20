//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/items/baseItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("seafood basket");
    addAlias("basket");
    addAlias("shellfish basket");

    addAdjectives(({ "woven", "damp", "shellfish-filled", "market", "sturdy" }));
    addDescriptionTemplate("a ##Adjective## seafood basket brimming with shellfish");

    addTimeOfDayDescription("dawn", ({
        ". The basket is freshly filled with clams and mussels, still damp with seawater",
        ". At dawn, the basket sits beside the catch, ready for sorting",
        ". The scent of brine and shellfish is sharp in the morning air"
        }));
    addTimeOfDayDescription("morning", ({
        ". The basket is sorted by vendors, shellfish glistening in the light",
        ". Fishermen add fresh crabs and shrimp to the basket",
        ". Gulls gather nearby, eyeing the seafood hungrily"
        }));
    addTimeOfDayDescription("noon", ({
        ". The basket sits in the sun, shellfish kept cool under wet seaweed",
        ". Buyers inspect the basket, selecting the freshest catch",
        ". The air is filled with the mingled scents of salt and shellfish"
        }));
    addTimeOfDayDescription("afternoon", ({
        ". The basket is half-empty, the remaining shellfish glistening in the light",
        ". Vendors repack the basket, keeping the seafood cool and moist",
        ". The dock is quieter, but the basket still draws the occasional customer"
        }));
    addTimeOfDayDescription("evening", ({
        ". The basket is nearly empty, only a few shellfish left at day's end",
        ". The air cools, and the basket is packed away for the night",
        ". Gulls pick at scraps left behind as the market closes"
        }));
    addTimeOfDayDescription("dusk", ({
        ". The basket is closed and stacked with others in the fading light",
        ". Vendors tally their sales, the basket nearly empty",
        ". The scent of shellfish lingers as the dock empties"
        }));
    addTimeOfDayDescription("night", ({
        ". The basket is covered and left in the cool night air",
        ". Only the faint scent of shellfish remains as the dock grows quiet",
        ". Lanterns cast dim light on the stacked baskets"
        }));

    addSeasonDescription("spring", ({
        " with the first shellfish of the season, fresh and plentiful",
        " as the basket overflows with clams, mussels, and crabs",
        " with the air fresh and the shellfish glistening with morning dew"
        }));
    addSeasonDescription("summer", ({
        " with the basket packed with shrimp and crab, kept cool with seaweed",
        " as the sun warms the dock, vendors hurry to sell the day's catch",
        " with the air thick with the scent of shellfish and salt"
        }));
    addSeasonDescription("autumn", ({
        " with the basket filled with the last big catches before winter",
        " as the air turns crisp and the shellfish are packed tightly for storage",
        " with the dock quieter, but the basket still draws eager buyers"
        }));
    addSeasonDescription("winter", ({
        " with the basket rimed with frost, shellfish kept cold by the winter air",
        " as only the hardiest vendors brave the chill to sell their catch",
        " with the basket stacked high, awaiting transport to the market"
        }));

    addNearDarkDescriptionTemplate(
        "the outline of a basket is barely visible, with only a faint glint from shells"
    );
    addLowLightDescriptionTemplate(
        "a seafood basket sits on the dock, its contents hard to distinguish in the gloom"
    );
    addDimLightDescriptionTemplate(
        "a basket packed with shellfish, shells glinting in the faint light"
    );
    addSomeLightDescriptionTemplate(
        "a sturdy basket filled with fresh shellfish, kept cool under wet seaweed"
    );
    addItemTemplate(
        "The basket is woven from sturdy reeds, its sides damp with seawater. "
        "Inside, freshly gathered shellfish-clams, mussels, crabs, and shrimp-"
        "are packed under wet seaweed. The scent of salt and shellfish is strong, "
        "and the basket is marked with the name of the local fishmonger."
    );
}
