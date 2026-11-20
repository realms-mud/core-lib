//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Miraen sets down her fine file "
        "and wipes the dust from her hands.");
    addTopic("gem work", "@S@'A good setting protects a stone without "
        "hiding it. Bring me the piece and tell me how it will be worn.'");
    addTopic("stone setting", "@D@Miraen turns a small setting "
        "under the light. @S@'The prongs must hold firm without "
        "pressing into the stone. A fine setting is careful work, "
        "not merely a pretty frame.'");
    addTopic("damaged stones", "@S@'A chip can sometimes be cut away. "
        "A crack through the center is another matter. I inspect "
        "the stone before I promise anything.'");
    addTopic("stone origins", "@S@'Color and inclusions can suggest "
        "where a stone formed, but trade changes hands many times. "
        "I can offer an informed guess, not a history I cannot prove.'");
    addTopic("repair limits", "@S@'A repair should protect what "
        "remains, not pretend the damage never happened. I will "
        "explain the risks before I touch a stone.'");

    addResponse("first conversation", "Can you repair a setting?",
        "@S@'If the metal is sound and the stone is not cracked, I can "
        "usually make it right.'");
    addResponseTopic("first conversation", "Can you repair a setting?",
        "gem work");
    addResponse("first conversation", "Can you set a loose stone?",
        "@S@'Yes. Tell me how the piece will be worn and I will "
        "suggest a setting that protects it.'");
    addResponseTopic("first conversation", "Can you set a loose stone?",
        "stone setting");
    addResponse("first conversation", "Can you repair a chipped gem?",
        "@S@'Let me examine it first. Some chips can be worked "
        "around, but I will not risk the whole stone to hide a flaw.'");
    addResponseTopic("first conversation",
        "Can you repair a chipped gem?", "damaged stones");
    addResponse("gem work", "How do you choose a setting?",
        "@S@'By the shape of the stone and how often it will be "
        "worn. A ring must survive daily use; a display piece has "
        "different needs.'");
    addResponseTopic("gem work", "How do you choose a setting?",
        "stone setting");
    addResponse("damaged stones", "Can you tell where a gem came from?",
        "@S@'Sometimes the cut and color offer clues, but I will "
        "not claim certainty when the evidence is thin.'");
    addResponseTopic("damaged stones",
        "Can you tell where a gem came from?", "stone origins");
    addResponse("first conversation", "What can you tell me about this gem?",
        "@S@'I can examine its color, inclusions, and cut. Each "
        "clue narrows the possibilities, but seldom proves the source.'");
    addResponseTopic("first conversation",
        "What can you tell me about this gem?", "stone origins");
    addResponse("stone origins", "Can you certify its value?",
        "@S@'I can describe its quality and give a careful estimate. "
        "A formal valuation depends on the buyer and the market.'");
    addResponseTopic("stone origins", "Can you certify its value?",
        "gem work");
    addResponse("damaged stones", "What if the repair may weaken it?",
        "@S@'Then I will tell you before I begin. You may choose "
        "to leave it as it is.'");
    addResponseTopic("damaged stones",
        "What if the repair may weaken it?", "repair limits");
    addResponse("repair limits", "Would you refuse a repair?",
        "@S@'Yes, if the work would likely destroy the piece. I "
        "would rather disappoint you than conceal that risk.'");
}
