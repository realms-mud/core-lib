//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/interiors/baseInterior.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    Name("opulent shop");

    addAdjectives(({
        "luxurious shop with polished mahogany counters and crystal display cases",
        "richly appointed store where silk curtains frame arched windows",
        "spacious and elegant emporium with velvet cushioned chairs for "
            "discerning customers",
        "high-end boutique where the scent of exotic spices and perfumes lingers",
        "sumptuous merchant hall where gold-trimmed shelves hold rare goods",
        "prestigious establishment with plush carpets and gilded mirrors",
        "refined shop where wealthy patrons browse under crystal chandeliers",
        "truly exquisite store with ornate ceiling frescos and marble pillars",
        "lavish merchant space where rare artifacts rest on satin cushions",
        "beautifully decorated boutique with stained glass windows filtering light",
        "grand emporium where exotic woods and precious metals adorn every surface",
        "large and upscale merchant hall with private alcoves for wealthy clientele",
        "fashionable shop where incense burns in silver censers by the door",
        "meticulously arranged store where each item is displayed as art",
        "gleaming establishment where brass fittings shine in lamplight",
        "resplendent shop with walls adorned in imported tapestries",
        "tasteful boutique where master craftworks are displayed on pedestals",
        "majestic store where guild emblems are inlaid in the wooden floor",
        "wealthy merchant's shop with a roaring hearth and comfortable seating",
        "quite impressively furnished establishment catering to nobility and merchants",
        "quite opulent trading house where exotic goods from distant lands are sold",
        "very artfully decorated shop with flowering plants in painted porcelain pots",
        "sophisticated boutique where patrons are served by liveried attendants"
        }));

    addDescriptionTemplate("a ##Adjective##");

    addNearDarkDescriptionTemplate(
        "a shadowy shop where only the glint of precious metals and glass is "
        "visible in the darkness"
    );

    addLowLightDescriptionTemplate(
        "a dimly lit shop, where the glow of oil lamps reveals gleaming wood "
        "and the sparkle of merchandise"
    );

    addDimLightDescriptionTemplate(
        "a dimly-lit ##Adjective##, the golden light from ornate lanterns casting "
        "a warm glow over the luxurious interior"
    );

    addSomeLightDescriptionTemplate(
        "a well-lit ##Adjective##, sunlight streaming through stained glass "
        "windows to illuminate the exquisite wares and ornate furnishings"
    );
}
