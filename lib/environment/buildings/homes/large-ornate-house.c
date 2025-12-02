//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/buildings/baseBuilding.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("large ornate house");
    setFloorPlanType("house");

    addAdjectives(({
        "impressive", "ornate", "three-story", "elaborate", "luxurious", "stately"
        }));

    // Basic description template
    addDescriptionTemplate(
        "a ##Adjective## house made of limestone and brick, with decorative "
        "gables and leaded glass windows"
    );

    // Time of day variations
    addTimeOfDayDescription("dawn", ({
        ". The first light of day touches the upper stories first, illuminating "
        "ornate carvings and decorative elements along the roofline",
        ". At dawn, the house emerges from darkness piece by piece, revealing "
        "its architectural splendor as the light strengthens"
        }));

    addTimeOfDayDescription("morning", ({
        ". Morning sunlight plays across the facade, highlighting the contrast "
        "between pale limestone quoins and deep red brick",
        ". The house displays its grandeur fully in the morning light, from "
        "elaborately carved lintels to decorative ironwork at the windows"
        }));

    addTimeOfDayDescription("noon", ({
        ". At midday, the house stands resplendent, its many windows gleaming "
        "and its ornate details casting precise shadows",
        ". The three stories rise impressively in the noon sun, the limestone "
        "and brick facade a testament to wealth and taste"
        }));

    addTimeOfDayDescription("afternoon", ({
        ". The afternoon light brings warmth to the rich materials, limestone "
        "and brick alike glowing with the day's accumulated heat",
        ". Shadows begin to lengthen across the formal garden, emphasizing the "
        "house's impressive height and elaborate detailing"
        }));

    addTimeOfDayDescription("evening", ({
        ". As evening falls, lamps are lit throughout the three stories, each "
        "leaded glass window becoming a glowing jewel in the facade",
        ". The house seems designed for evening entertainment, with multiple "
        "well-lit windows suggesting spacious rooms within"
        }));

    addTimeOfDayDescription("dusk", ({
        ". At dusk, the ornate silhouette of the house dominates its "
        "surroundings, decorative elements still visible against the sky",
        ". The last light catches on carved details and metalwork, highlighting "
        "the craftsmanship lavished on this impressive dwelling"
        }));

    addTimeOfDayDescription("night", ({
        ". By night, the house becomes a constellation of golden windows, "
        "systematically illuminated from within by unseen servants",
        ". Moonlight reveals the ornate details in silver and shadow, the "
        "impressive facade no less striking for the hour"
        }));

    // Seasonal variations
    addSeasonDescription("spring", ({
        " with formal gardens coming into bloom and delicate climbing vines "
        "beginning to scale trellises set against the walls",
        " where spring light seems to particularly favor the ornate details, "
        "bringing each carved flourish and decorative element into clear focus"
        }));

    addSeasonDescription("summer", ({
        " with tall windows open behind lace curtains and servants occasionally "
        "visible bringing refreshments to unseen occupants",
        " surrounded by gardens at their peak splendor, each bed and border "
        "designed to complement the house's elaborate architecture"
        }));

    addSeasonDescription("autumn", ({
        " with ivy turning crimson along the limestone accents and the formal "
        "gardens transitioning to autumnal displays",
        " where the slanting seasonal light creates dramatic contrasts across "
        "the facade, emphasizing the depth of architectural details"
        }));

    addSeasonDescription("winter", ({
        " with smoke rising from multiple ornate chimneys and frost outlining "
        "each decorative element along the roofline",
        " where evergreen garlands and winter decorations adorn the entrance, "
        "seasonal touches adding to the house's inherent opulence"
        }));

    // Lighting condition descriptions
    addNearDarkDescriptionTemplate(
        "a large, complex structure with multiple levels and what appear to be "
        "decorative elements along its roofline"
    );
    addLowLightDescriptionTemplate(
        "an impressive three-story building with ornate details visible even in "
        "the dim light"
    );
    addDimLightDescriptionTemplate(
        "a large ornate house with three stories, built of contrasting limestone "
        "and brick with decorative architectural features"
    );
    addSomeLightDescriptionTemplate(
        "an impressive three-story house constructed of red brick with limestone "
        "accents, featuring ornate gables, leaded glass windows, and elaborate "
        "decorative details throughout its facade"
    );

    // Single item template
    addItemTemplate(
        "The house represents the pinnacle of residential architecture, rising "
        "three full stories from a foundation of dressed limestone. The walls "
        "combine rich red brick with pale limestone quoins and accents, creating "
        "a striking visual contrast. Every aspect displays elaborate ornament, "
        "from carved stone lintels to decorative ironwork at the many leaded "
        "glass windows. Multiple chimneys rise from the complex roofline, where "
        "ornate gables and decorative finials create a dramatic silhouette. "
        "Formal gardens surround the structure, carefully designed to provide an "
        "appropriate setting for such architectural splendor."
    );

    addSourceOfLight(6);
}
