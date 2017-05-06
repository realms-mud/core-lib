inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("physical");
    addHitDictionary(({
        "bash", "slam", "slap", "pummel", "crush", "pound", "whip", "smack",
        "assault" }));

    addSimileDictionary(({
        "whacking ##TargetPossessive## ##BodyPart## soundly", "repeatedly in "
        "the ##BodyPart##", "with a ##BodyPart##-shattering force" }));
        
    addMissMessage("##AttackerName## ##Infinitive::thrash## ##AttackerPossessive##"
        " tail at nothing.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
            "##SimileDictionary## with ##AttackerPossessive## tail.","1-50");
}




