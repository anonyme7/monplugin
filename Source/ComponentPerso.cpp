/*
  ==============================================================================

    ComponentPerso.cpp
    Created: 19 Apr 2025 9:17:10pm
    Author:  olivier

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ComponentPerso.h"
#include "PluginEditor.h"

//==============================================================================
ComponentPerso::ComponentPerso()
{
    setSize(50, 50);

}

ComponentPerso::~ComponentPerso()
{
}

void ComponentPerso::paint (juce::Graphics& g)
{
    if (isSelected)
    {
        g.setColour(juce::Colours::red);
        g.drawRect(getLocalBounds(), 2.0f); // Bordure rouge, épaisseur 2 pixels
    }
}

void ComponentPerso::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


void ComponentPerso :: mouseDown(const juce::MouseEvent& event)
{
    if (auto* editor = dynamic_cast<MonpluginAudioProcessorEditor*>(getParentComponent()))
        editor->selectComponent(this);

    if (event.mods.isRightButtonDown())
    {
        // Créer un menu contextuel
        juce::PopupMenu menu;

        // Ajouter deux options
        menu.addItem(1, "Inputs");
        menu.addItem(2, "Outputs");

        // Afficher le menu à la position du clic
        // event.position est relatif au composant, on convertit en coordonnées globales
        auto screenPos = getScreenPosition() + event.position.toInt();

        // Montrer le menu et récupérer l'ID de l'option sélectionnée
        menu.showMenuAsync(juce::PopupMenu::Options().withTargetScreenArea({ screenPos.x, screenPos.y, 1, 1 }),
            [this](int result)
            {
                if (result == 1)
                {
                    // Afficher une boîte de dialogue avec un menu déroulant
                    juce::AlertWindow dialog("Choisir une valeur",
                        "Sélectionnez une valeur de 1 à 10 :",
                        juce::AlertWindow::QuestionIcon);

                    // Créer les options du menu déroulant (1 à 10)
                    juce::StringArray choices;
                    for (int i = 1; i <= 10; ++i)
                        choices.add(juce::String(i));

                    // Ajouter un menu déroulant
                    dialog.addComboBox("valueSelector", choices, "Valeur");

                    // Ajouter des boutons
                    dialog.addButton("OK", 1, juce::KeyPress(juce::KeyPress::returnKey));
                    dialog.addButton("Annuler", 0, juce::KeyPress(juce::KeyPress::escapeKey));

                    // Afficher la boîte de dialogue et gérer le résultat
                    if (1 == 1)
                    {
                        // Récupérer la valeur sélectionnée (index commence à 1)
                        int selectedValue = dialog.getComboBoxComponent("valueSelector")->getSelectedItemIndex() + 1;
                        juce::Logger::writeToLog("Valeur sélectionnée : " + juce::String(selectedValue));
                        // Exemple : utiliser la valeur dans le processeur
                        // processor.setParameterValue(selectedValue);
                    }
                    else
                    {
                        juce::Logger::writeToLog("Dialogue annulé");
                    }
                }
                else if (result == 2)
                {
                    // Action pour Option 2
                    juce::Logger::writeToLog("Option 2 sélectionnée");
                }
        
            });
    }
}



void ComponentPerso :: setSelected(bool selected)
{
    isSelected = selected;
    repaint(); // Redessiner pour mettre à jour la bordure
}

bool ComponentPerso :: isComponentSelected() const { return isSelected; }



