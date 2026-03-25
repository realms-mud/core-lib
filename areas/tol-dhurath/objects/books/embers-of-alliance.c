//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/items/book.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    set("name", "Embers of Alliance");
    set("short", "A folio of treaties and counsel");
    set("title", "Embers of Alliance: The Making of the Eastern League");
    set("aliases", ({ "embers", "embers of alliance", "eastern league",
        "alliance book", "folio", "book" }));
    set("long", "A folio compiling dispatches, treaties, and counsel that "
        "led to the formation of the alliance. It mixes narrative with "
        "snippets of correspondence and council notes.");

    addChapter("Prefatory Letters",
        "Eldarion's letters to Werra show a patient diplomacy. He urged a "
        "durable security pact that balanced respect for local autonomy "
        "with clear expectations of mutual aid. His instructions were "
        "practical: list what each city could muster, set rendezvous "
        "points, and identify potential choke points. The letters stress "
        "timeliness; war rewards those who can move quickly and starves "
        "those who dither.");

    addChapter("On Bregandil's Expedition",
        "Bregandil's fleet was not a random armada but a chosen force of "
        "fast caravels and local pilots. He carried gifts and coin, but "
        "also engineers, smiths, and a modest garrison to secure a "
        "beachhead. The choice of men reflected a plan: establish a "
        "sustainable foothold rather than a mere raid.");

    addChapter("On the Founding of Eledhel",
        "Bregandil selected a site with a natural harbor and defensible "
        "hills. Colonists were offered land grants and seed; craftsmen "
        "gained tax relief. Administrators set up grain stores and docks, "
        "while scouts cut a road inland. The city's growth was engineered "
        "with incentives and a pragmatic hand.");

    addChapter("Diplomatic Maneuvers",
        "Eldarion's envoys courted chieftains with both gifts and guarantees: "
        "retain your customs, keep your local leaders, but swear to assist "
        "in times of invasion. This guarantee of internal autonomy in "
        "exchange for external fidelity proved decisive in securing a "
        "patchwork coalition.");

    addChapter("The Crown for Bregandil",
        "The crown made for Bregandil was as much political as ceremonial. "
        "Its crafting involved the smiths of Dur-Hal, and its blessing by "
        "Eldarion was a legal act: it bound Bregandil's house to Eneldhor by "
        "oath and gift. Such acts convert personal loyalty into institutional "
        "obligation.");

    addChapter("On the Aegis Guard",
        "Cuilornir's Aegis Guard borrowed discipline from the Werrics but "
        "bound its loyalty to the city of Eledhel. Their oaths emphasized "
        "duty to the city and its charter, which served to prevent easy "
        "foreign influence. They were modeled for defense and civic order.");

    addChapter("Trade and Sea Lanes",
        "Securing sea lanes gave the alliance a logistical advantage. "
        "Convoys moved to Eledhel under naval escort, carrying tools, "
        "grain, and blacksmiths. Control of the coast turned a static "
        "defense into a mobile network of resupply.");

    addChapter("The Cost of Treaty",
        "Treaties required concessions. Eldarion ceded certain levies and "
        "allowed local governors more autonomy than traditional feudal "
        "ties. This pragmatic adjustment bought stability and saved lives "
        "in the long run: the price of compromise sometimes buys more "
        "than the price of war.");

    addChapter("Afterword: The Work of Many Hands",
        "No alliance endures on banners alone. Notaries, porters, merchants "
        "and midwives made the work possible. The volume honors the mundane "
        "labor that secures victory: storekeepers who kept accounts, "
        "carpenters who built docks, and farmers who fed armies.");
}
