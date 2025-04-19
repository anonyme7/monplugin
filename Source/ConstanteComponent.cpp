/*
  ==============================================================================

    Constante.cpp
    Created: 19 Apr 2025 9:46:49am
    Author:  olivier

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ConstanteComponent.h"
#include "PluginEditor.h"

//==============================================================================
ConstanteComponent::ConstanteComponent()
{
    setSize(50, 50);

}

ConstanteComponent::~ConstanteComponent()
{
 
}

void ConstanteComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::green);
    g.setColour(juce::Colours::white);
    g.drawText("Const", getLocalBounds(), juce::Justification::centred);
}

void ConstanteComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void ConstanteComponent::mouseDown(const juce::MouseEvent& event)
{
    if (event.mods.isRightButtonDown())
    {
        juce::PopupMenu menu;
        menu.addItem(1, "Option 1");
        menu.addItem(2, "Option 2");
        menu.addItem(3, "Supprimer");

        menu.showMenuAsync(juce::PopupMenu::Options(),
            [this](int result)
            {
                if (result == 0) return;
                if (result == 1)
                {
                    juce::AlertWindow dialog("Input Count", "Entrez le nombre d'inputs :", juce::MessageBoxIconType::NoIcon);

                    // Ajouter une zone de saisie pour un entier
                    dialog.addTextEditor("inputCount", "1", "Nombre d'inputs");

                    // Ajouter les boutons OK et Cancel
                    dialog.addButton("OK", 1, juce::KeyPress(juce::KeyPress::returnKey));
                    dialog.addButton("Cancel", 0, juce::KeyPress(juce::KeyPress::escapeKey));

                    // Afficher la boîte de dialogue et gérer le résultat
                    if (1 == 1) // Si OK est cliqué
                    {
                        juce::String inputText = dialog.getTextEditorContents("inputCount");
                        int inputCount = inputText.getIntValue();
                        if (inputCount >= 0) // Vérification basique
                        {
                            juce::Logger::writeToLog("Nombre d'inputs defini : " + juce::String(inputCount));
                            // Ici, tu peux stocker inputCount dans AdditionComponent si besoin
                        }
                    }
                }
                else if (result == 2)
                {
                    juce::Logger::writeToLog("Option 2 sélectionnée");
                }
                else if (result == 3)
                {
                    // Supprimer ce composant
                    if (auto* parent = dynamic_cast<MonpluginAudioProcessorEditor*>(getParentComponent()))
                    {
                        parent->removeConstanteComponent(this);
                    }
                }
            });
    }
}
