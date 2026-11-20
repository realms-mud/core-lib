//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Durma sets down a hammer and "
        "looks you over from shoulder to boot.");
    addTopic("armor fit", "@S@'Armor should move with you, not against "
        "you. A poor fit turns a long march into a punishment.'");
    addTopic("repairs", "@D@Durma turns the armor over in her hands. "
        "@S@'A loose strap can be replaced. A split ring needs "
        "attention before it becomes a gap. I will tell you plainly "
        "when a repair is not worth the cost.'");
    addTopic("armor care", "@S@'Keep mail clean and dry. Leather "
        "needs oil, not a soaking. Check every buckle before you "
        "leave town; the road will find whatever you forgot.'");
    addTopic("field repairs", "@S@'A spare strap and a small awl can "
        "keep a harness together for a while. A cracked plate or "
        "broken rivet needs a proper bench, not a roadside guess.'");
    addTopic("armor materials", "@S@'Every material asks something "
        "different of its wearer. Mail needs cleaning, leather needs "
        "careful drying, and plate needs a fit that lets you move.'");

    addResponse("first conversation", "Can you repair my armor?",
        "@S@'Set it on the bench. I will tell you what can be fixed "
        "before I start.'");
    addResponseTopic("first conversation", "Can you repair my armor?",
        "armor fit");
    addResponse("first conversation", "How do I choose armor?",
        "@S@'Start with where you expect to wear it. A guard on a "
        "wall needs something different from a traveler on foot.'");
    addResponseTopic("first conversation", "How do I choose armor?",
        "armor fit");
    addResponse("armor fit", "What if the armor is damaged?",
        "@S@'Bring it here before you wear it again. I will inspect "
        "the seams, straps, and fastenings.'");
    addResponseTopic("armor fit", "What if the armor is damaged?",
        "repairs");
    addResponse("repairs", "Can I maintain it myself?",
        "@S@'You should. Clean it after use, dry it away from direct "
        "heat, and check the fastenings. Ask me if a piece is bent.'");
    addResponseTopic("repairs", "Can I maintain it myself?",
        "armor care");
    addResponse("armor care", "What should I check before a journey?",
        "@S@'Every strap, every buckle, and the places where one "
        "piece meets another. If anything shifts when you move, "
        "come back before you go.'");
    addResponseTopic("armor care", "What should I check before a journey?",
        "field repairs");
    addResponse("first conversation", "Which armor is easiest to maintain?",
        "@S@'That depends on the material and how you travel. I can "
        "explain what each kind asks of you.'");
    addResponseTopic("first conversation",
        "Which armor is easiest to maintain?", "armor materials");
    addResponse("field repairs", "Can I keep wearing a cracked piece?",
        "@S@'No. A crack can spread under a blow. Bring it to a smith "
        "before trusting it again.'");
    addResponseTopic("field repairs", "Can I keep wearing a cracked piece?",
        "repairs");
    addResponse("armor materials", "What matters more, weight or coverage?",
        "@S@'The protection you need and the movement you can keep. "
        "A fine suit is no use if it leaves you helpless.'");
    addResponseTopic("armor materials",
        "What matters more, weight or coverage?", "armor fit");
}
