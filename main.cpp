#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

constexpr int TILE=20;

struct World{
    std::vector<std::vector<int>> world={
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1},
        {1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
        {1,1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,1,1},
        {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    int score=0;
    int row=world.size();
    int col=world[0].size(); 

    void draw(sf::RenderWindow& window){
        sf::RectangleShape wall(sf::Vector2f(TILE-1, TILE-1)); 
        sf::CircleShape food(float(TILE-18));
        sf::CircleShape pacman(float(TILE-10));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(world[i][j]==1){
                    wall.setFillColor(sf::Color::Blue);
                    wall.setPosition({float(j*TILE), float(i*TILE)});
                    window.draw(wall);
                }
                if(world[i][j]==2){
                    food.setFillColor(sf::Color::Yellow);
                    food.setPosition({float(j*TILE), float(i*TILE)});
                    window.draw(food);
                } 
            }
        }
    }
};

struct Enemy{ //4 SERA SU IDENTIDAD
    std::vector<std::pair<int,int>> coords;
    enum Color; //azul, rojo, verde, cyan
    sf::CircleShape enemy;

    Enemy(World& w): used(4, false){
        Color={cero, uno, dos, tres};
        coords={{1,6},{1,26},{w.row-4,6},{w.row-4,26}};
        enemy.setRadius(float(TILE-11));
    }

    void init(World& w, int& i){
        //una funcion segun una lista de posiciones disponibles
        //coords={{1,3},{1,26},{w.row-4,3},{w.row-4,26}};
        w.world[coords[i].first][coords[i].second]=4;
    }

    void update(World& w){

    }

    void draw(sf::RenderWindow& window, World& w){

    }
};

struct User{ //3 serà su identidad
    int x=10, y=15; //posicion antigua que servirà para el frame suave
    int nx, ny;
    float speed=1.f;
    sf::CircleShape user;

    enum Dir{ LEFT, DOWN, RIGHT, UP};
    Dir dir=RIGHT;

    User(){
        user.setRadius(float(TILE-12));
        user.setPosition(sf::Vector2f(TILE*10, TILE*10));
        user.setFillColor(sf::Color::Yellow);
    }

    void init(World& w){
        w.world[x][y]=3;
    }

    void update(World& w){
        int dx=0, dy=0;
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) dy=-1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) dy=1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) dx=-1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) dx=1;

        nx=x+dx;
        ny=y+dy;

        //OBSTACULOS
        if(nx<0 || nx>w.row-1 || ny<0 || ny>w.col-1 || w.world[nx][ny]==1) return;
        
        if(nx==13 && ny>=w.col-1) ny=0;
        else if(nx==13 && ny==0) ny=w.col-1;

        if(nx==14 && ny>=w.col-1) ny=0;
        else if(nx==14 && ny==0) ny=w.col-1;

        if(w.world[nx][ny]==2) w.score++;

        w.world[x][y]=0;
        w.world[nx][ny]=3; //IDENTIDAD DEL USUARIO 3 

        //AQUI ACTUALIZAMOS
        x=nx;
        y=ny;
    }

    void draw(sf::RenderWindow& window, float& alpha){
        float newX=x + (nx-x) * alpha;
        float newY=y + (ny-y) * alpha;

        user.setPosition(sf::Vector2f(newY*TILE, newX*TILE));
        window.draw(user);
    }
};

struct Food{
    //recordar regla de oro:
    //si pacman come, lugar se pone en 0, es decir, lugar vacio
    void init(World& _w){
        for(int i=0; i<_w.row; i++){
            for(int j=0; j<_w.col; j++){
                if(_w.world[i][j]==0) _w.world[i][j]=2;
            }
        }
    }
};

void execute(){
    World _w;
    Food _f;
    User _u;
    std::vector<Enemy> enemies;

    for(int i=0; i<4; i++){
        Enemy e(_w);
        e.init(_w, i);
    }

    sf::RenderWindow window{
        sf::VideoMode({
                static_cast<unsigned>(_w.row*TILE),
                static_cast<unsigned>(_w.col*TILE)
        }),
        "PACMAN"
    };

    window.setFramerateLimit(60);

    _f.init(_w);
    _u.init(_w);

    sf::Clock clock;
    float timer=0;
    float delay=0.07;

    while(window.isOpen()){
        while(const std::optional event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()) window.close(); 
        }

        float t=clock.restart().asSeconds();
        timer+=t;

        if(timer>delay){
            _u.update(_w);
            timer-=delay;
        }
        float alpha=timer/delay;

        window.clear();
        _w.draw(window);
        _u.draw(window, alpha);
        window.display();
    }
}

int main(){
    execute();
    return 0;
}

//g++ -o m main.cpp -lsfml-graphics -lsfml-window -lsfml-system
