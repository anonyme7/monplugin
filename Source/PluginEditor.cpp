/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "AdditionComponent.h"
#include "ConstanteComponent.h"
#include "SliderComponent.h"

//==============================================================================
MonpluginAudioProcessorEditor::MonpluginAudioProcessorEditor (MonpluginAudioProcessor& p): AudioProcessorEditor (&p), audioProcessor (p), apvts(p.getAPVTS())
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 800);

   
   

    // Create sliders and attachments
    //gainSlider = std::make_unique<juce::Slider>();

    gainSlider.setRange(0.0, 1.0, 0.01); // Plage et pas
    gainSlider.setSliderStyle(juce::Slider::LinearHorizontal); // Style
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20); //

    addAndMakeVisible(gainSlider);
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "gain", gainSlider);


}

MonpluginAudioProcessorEditor::~MonpluginAudioProcessorEditor()
{
}

//==============================================================================
void MonpluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void MonpluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    //gainSlider->setBounds(getLocalBounds().reduced(20));

    gainSlider.setBounds(getWidth() / 2 - 100, getHeight() / 2 - 100, 200, 200);
}

void  MonpluginAudioProcessorEditor::mouseDown(const juce::MouseEvent& event)
{
    // Vérifier si c'est un clic droit
    if (event.mods.isRightButtonDown())
    {
        // Créer un menu contextuel
        juce::PopupMenu menu;

        selectComponent(nullptr);

        // Ajouter des options au menu
        menu.addItem(1, "addition");
        menu.addItem(2, "Slider");
        menu.addSeparator(); // Ajoute une ligne de séparation
        menu.addItem(3, "Option 3");

        // Afficher le menu et gérer la sélection
        menu.showMenuAsync(juce::PopupMenu::Options().withTargetComponent(this)
            .withMousePosition(),
            [this, event](int result)
            {
                // Gérer le choix de l'utilisateur
                if (result == 1)
                {
                    AdditionComponent* additionComp = new AdditionComponent();
                    additionComp->setSize(50, 50);
                    // Positionne le composant à l'endroit du clic
                    additionComp->setTopLeftPosition(event.getPosition().x, event.getPosition().y);
                    components.add(additionComp);
                    addAndMakeVisible(additionComp);
                }
                if (result == 2)
                {
                    SliderComponent* SliderComp = new SliderComponent();
                    SliderComp->setSize(50, 50);
                    SliderComp->setTopLeftPosition(event.getPosition().x, event.getPosition().y);
                    components.add(SliderComp);
                    addAndMakeVisible(SliderComp);
                }
                if (result == 3)
                {
                    juce::Logger::writeToLog("Option 3 sélectionnée");
                    // Ajoutez votre logique ici
                }
            });
    }

}

void MonpluginAudioProcessorEditor::selectComponent(juce::Component* component)
{
    // Désélectionner l'ancien composant
    if (selectedComponent != nullptr)
    {
        if (auto* comp = dynamic_cast<ComponentPerso*>(selectedComponent))
            comp->setSelected(false);
    }

    // Sélectionner le nouveau composant
    selectedComponent = component;
    if (component != nullptr)
    {
        if (auto* comp = dynamic_cast<ComponentPerso*>(component))
            comp->setSelected(true);
    }
}




