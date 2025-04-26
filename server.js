const express = require('express');
const app = express();

app.use(express.json());

app.get('/', (req, res) => {
    res.send('🌾 Smart Farming System (Node Backend) Running Successfully!');
});

app.post('/farmer', (req, res) => {
    const { name, crop, region } = req.body;

    const response = {
        weather_advice: "Ideal for maize and pulses. Monitor humidity to prevent fungal growth.",
        storage_options: [
            { city: "Chennai", vacant_tonnes: 500 },
            { city: "Delhi", vacant_tonnes: 700 },
            { city: "Hyderabad", vacant_tonnes: 600 }
        ],
        disease_info: [
            { disease: "Rust", solution: "Use Propiconazole" },
            { disease: "Blast", solution: "Use Tricyclazole" }
        ],
        govt_schemes: [
            "PM-KISAN",
            "eNAM",
            "PMFBY"
        ]
    };
    res.json(response);
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
