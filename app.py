from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/')
def home():
    return "🌾 Smart Farming System (Python Backend) Running Successfully!"

@app.route('/farmer', methods=['POST'])
def farmer_data():
    data = request.get_json()
    name = data.get('name')
    crop = data.get('crop')
    region = data.get('region')

    # Mock Response Example
    response = {
        "weather_advice": "Expect heavy rains; prepare for pest attacks like stem borers.",
        "storage_options": [
            {"city": "Chennai", "vacant_tonnes": 500},
            {"city": "Delhi", "vacant_tonnes": 700},
            {"city": "Hyderabad", "vacant_tonnes": 600}
        ],
        "disease_info": [
            {"disease": "Rust", "solution": "Spray Propiconazole"},
            {"disease": "Blast", "solution": "Apply Tricyclazole"}
        ],
        "govt_schemes": [
            "PM-KISAN",
            "eNAM (National Agriculture Market)",
            "PMFBY (Crop Insurance)"
        ]
    }
    return jsonify(response)

if __name__ == '__main__':
    app.run(debug=True, port=5000)
